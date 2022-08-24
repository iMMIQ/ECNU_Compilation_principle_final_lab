#include "ParserUtils.h"
#include "../AST/ArithBinaryExpr.h"
#include "../AST/AssgStmt.h"
#include "../AST/BoolBinaryExpr.h"
#include "../AST/CompoundStmt.h"
#include "../AST/IfStmt.h"
#include "../AST/IntNumExpr.h"
#include "../AST/RealNumExpr.h"
#include "../AST/WhileStmt.h"
#include <iostream>

std::map<Token, int> ParserUtils::binary_operator_precedence =
    init_binary_operator_precedence();

Token ParserUtils::get_next_token(std::vector<std::string> &cur_stmt) {
  auto [token, stmt] = Lexer::get_token();
  cur_stmt.emplace_back(stmt);
  return cur_token = token;
}

Token ParserUtils::get_next_token() {
  std::tie(cur_token, cur_input) = Lexer::get_token();
  return cur_token;
}

std::map<Token, int> ParserUtils::init_binary_operator_precedence() {
  std::map<Token, int> ret;
  ret[Token::Less] = 10;
  ret[Token::LessEqual] = 10;
  ret[Token::Greater] = 10;
  ret[Token::GreaterEqual] = 10;
  ret[Token::Equal] = 10;
  ret[Token::Plus] = 20;
  ret[Token::Minus] = 20;
  ret[Token::Multiplies] = 40;
  ret[Token::Divides] = 40;
  return ret;
}
bool ParserUtils::is_bool_binary_operator(Token cur_token) {
  return cur_token == Token::Less || cur_token == Token::LessEqual ||
         cur_token == Token::Greater || cur_token == Token::GreaterEqual ||
         cur_token == Token::Equal;
}
bool ParserUtils::is_arith_binary_operator(Token cur_token) {
  return cur_token == Token::Plus || cur_token == Token::Minus ||
         cur_token == Token::Multiplies || cur_token == Token::Divides;
}
int ParserUtils::get_token_precedence(Token cur_token) {
  if (cur_token == Token::End || cur_token == Token::RightRoundBracket) {
    return -1;
  }
  if (is_arith_binary_operator(cur_token) ||
      is_bool_binary_operator(cur_token)) {
    return binary_operator_precedence[cur_token];
  }
  return -2;
}
std::unique_ptr<Expr>
ParserUtils::parse_expr_paren(std::vector<std::string> &input) {
  std::ignore = get_next_token(input);
  auto ret = ArithBinaryExpr::parse(input);
  if (!ret) {
    return nullptr;
  }
  if (cur_token != Token::RightRoundBracket) {
    handle_invalid(input, ")");
    return nullptr;
  }
  std::ignore = get_next_token(input);
  return ret;
}
std::unique_ptr<Expr>
ParserUtils::parse_expr_primary(std::vector<std::string> &input) {
  switch (cur_token) {
  case Token::ID: {
    auto id = IdExpr::parse<IdExpr>(input);
    if (identifiers.find(id->get_name()) == identifiers.end()) {
      recoverable_error = true;
      std::cerr << "The identifier '" << id->get_name()
                << "' used is not defined." << std::endl;
    }
    return id;
  }
  case Token::IntNum:
    return IntNumExpr::parse(input);
  case Token::RealNum:
    return RealNumExpr::parse(input);
  case Token::LeftRoundBracket:
    return parse_expr_paren(input);
  default:
    handle_invalid(input,
                   "an identifier, an integer number, a real number or '('");
    return nullptr;
  }
}
std::unique_ptr<Expr>
ParserUtils::parse_binary_operator_rhs(int expr_prec, std::unique_ptr<Expr> lhs,
                                       int bool_binary_operator_counter,
                                       std::vector<std::string> &input) {
  while (true) {
    if (cur_token == Token::Eof) {
      handle_eof();
      return nullptr;
    }
    int token_prec = get_token_precedence(cur_token);
    if (token_prec == -2) {
      handle_invalid(input, "a binary operator or ';'");
      return nullptr;
    }
    if (token_prec < expr_prec) {
      return lhs;
    }
    Token op = cur_token;
    if (is_bool_binary_operator(op)) {
      --bool_binary_operator_counter;
      if (bool_binary_operator_counter < 0) {
        std::cerr << "In '";
        std::copy(input.begin(), input.end() - 1,
                  std::ostream_iterator<std::string>(std::cerr, " "));
        std::cerr << input.back()
                  << "' , find too much binary compare operator." << std::endl;
        ParserUtils::recoverable_error = true;
      }
    }
    std::ignore = get_next_token(input);
    auto rhs = parse_expr_primary(input);
    if (!rhs) {
      return nullptr;
    }
    int next_prec = get_token_precedence(cur_token);
    if (token_prec < next_prec) {
      rhs = parse_binary_operator_rhs(token_prec + 1, std::move(rhs),
                                      bool_binary_operator_counter, input);
      if (!rhs) {
        return nullptr;
      }
    }
    if (is_bool_binary_operator(op)) {
      lhs =
          std::make_unique<BoolBinaryExpr>(op, std::move(lhs), std::move(rhs));
    } else {
      lhs =
          std::make_unique<ArithBinaryExpr>(op, std::move(lhs), std::move(rhs));
    }
  }
}
std::unique_ptr<Stmt> ParserUtils::parse_stmt_primary() {
  switch (cur_token) {
  case Token::ID:
    ParserUtils::error = false;
    return AssgStmt::parse();
  case Token::If:
    ParserUtils::error = false;
    return IfStmt::parse();
  case Token::While:
    ParserUtils::error = false;
    return WhileStmt::parse();
  case Token::LeftCurlyBracket:
    ParserUtils::error = false;
    return CompoundStmt::parse();
  default:
    if (!ParserUtils::error) {
      std::cerr << "In Statement, expect an identifier, 'If', 'While' or '{', "
                   "but found '"
                << ParserUtils::cur_input << "'." << std::endl;
      ParserUtils::error = true;
    }
    return nullptr;
  }
}

void ParserUtils::handle_invalid(const std::vector<std::string> &input,
                                 const std::string &expected) {
  if (cur_token == Token::Eof) {
    handle_eof();
  } else {
    std::cerr << "In '";
    std::copy(input.begin(), input.end() - 1,
              std::ostream_iterator<std::string>(std::cerr, " "));
    std::cerr << input.back() << "' , expected " << expected << ", but found '"
              << input.back() << "'." << std::endl;
  }
  error = true;
}
void ParserUtils::handle_eof() {
  std::cerr << "The program ended unexpectedly." << std::endl;
}
