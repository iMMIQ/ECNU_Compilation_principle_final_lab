#include "ParserUtils.h"
#include "../AST/ArithBinaryExpr.h"
#include "../AST/AssgStmt.h"
#include "../AST/BinaryExpr.h"
#include "../AST/BoolBinaryExpr.h"
#include "../AST/CompoundStmt.h"
#include "../AST/IdExpr.h"
#include "../AST/IfStmt.h"
#include "../AST/IntIdExpr.h"
#include "../AST/IntNumExpr.h"
#include "../AST/RealIdExpr.h"
#include "../AST/RealNumExpr.h"
#include "../AST/WhileStmt.h"

std::map<Token, int> ParserUtils::binary_operator_precedence =
    init_binary_operator_precedence();

Token ParserUtils::get_next_token() { return cur_token = Lexer::get_token(); }

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
  case Token::Int:
    return IdExpr::parse<IntIdExpr>();
  case Token::Real:
    return IdExpr::parse<RealIdExpr>();
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
  case Token::Int:
  case Token::Real:
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
template <class destinationT, typename sourceT>
std::unique_ptr<destinationT>
ParserUtils::dynamic_unique_cast(std::unique_ptr<sourceT> &&source) {
  if (!source) {
    return std::unique_ptr<destinationT>();
  }
  destinationT *dest_ptr = &dynamic_cast<destinationT &>(*source.get());

  source.release();
  return std::unique_ptr<destinationT>(dest_ptr);
}
template std::unique_ptr<ArithBinaryExpr>
ParserUtils::dynamic_unique_cast(std::unique_ptr<Expr> &&source);
template std::unique_ptr<BoolBinaryExpr>
ParserUtils::dynamic_unique_cast(std::unique_ptr<Expr> &&source);
