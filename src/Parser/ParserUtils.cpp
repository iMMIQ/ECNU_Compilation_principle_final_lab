#include "ParserUtils.h"
#include "../AST/ArithBinaryExpr.h"
#include "../AST/AssgStmt.h"
#include "../AST/BoolBinaryExpr.h"
#include "../AST/CompoundStmt.h"
#include "../AST/IfStmt.h"
#include "../AST/IntNumExpr.h"
#include "../AST/RealNumExpr.h"
#include "../AST/WhileStmt.h"

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
  // TODO: handle invalid
  return -1;
}
std::unique_ptr<Expr> ParserUtils::parse_expr_paren() {
  std::ignore = get_next_token();
  auto ret = ArithBinaryExpr::parse();
  if (!ret) {
    return nullptr;
  }
  if (cur_token != Token::RightRoundBracket) {
    // TODO: handle invalid
  }
  std::ignore = get_next_token();
  return ret;
}
std::unique_ptr<Expr> ParserUtils::parse_expr_primary() {
  switch (cur_token) {
  case Token::ID:
    return IdExpr::parse<IdExpr>();
  case Token::IntNum:
    return IntNumExpr::parse();
  case Token::RealNum:
    return RealNumExpr::parse();
  case Token::LeftRoundBracket:
    return parse_expr_paren();
  default:
    // TODO: handle invalid
    return nullptr;
  }
}
std::unique_ptr<Expr>
ParserUtils::parse_binary_operator_rhs(int expr_prec, std::unique_ptr<Expr> lhs,
                                       int bool_binary_operator_counter) {
  while (true) {
    int token_prec = get_token_precedence(cur_token);
    if (token_prec < expr_prec) {
      return lhs;
    }
    Token op = cur_token;
    if (is_bool_binary_operator(op)) {
      --bool_binary_operator_counter;
      if (bool_binary_operator_counter < 0) {
        // TODO: handle invalid
      }
    }
    std::ignore = get_next_token();
    auto rhs = parse_expr_primary();
    if (!rhs) {
      return nullptr;
    }
    int next_prec = get_token_precedence(cur_token);
    if (token_prec < next_prec) {
      rhs = parse_binary_operator_rhs(token_prec + 1, std::move(rhs),
                                      bool_binary_operator_counter);
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
    return AssgStmt::parse();
  case Token::If:
    return IfStmt::parse();
  case Token::While:
    return WhileStmt::parse();
  case Token::LeftCurlyBracket:
    return CompoundStmt::parse();
  default:
    // TODO: handle Invalid
    return nullptr;
  }
}
