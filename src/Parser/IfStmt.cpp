#include "../AST/IfStmt.h"
#include "ParserUtils.h"
std::unique_ptr<Stmt> IfStmt::parse() {
  if (ParserUtils::get_next_token() != Token::LeftRoundBracket) {
    // TODO: handle invalid
  }
  std::ignore = ParserUtils::get_next_token();
  auto bool_expr = BoolBinaryExpr::parse();
  if (bool_expr == nullptr) {
    // TODO: handle invalid
  }
  if (ParserUtils::cur_token != Token::RightRoundBracket) {
    // TODO: handle invalid
  }
  if (ParserUtils::get_next_token() != Token::Then) {
    // TODO: handle invalid
  }
  std::ignore = ParserUtils::get_next_token();
  auto then_stmt = ParserUtils::parse_stmt_primary();
  if (then_stmt == nullptr) {
    // TODO: handle invalid
  }
  if (ParserUtils::cur_token != Token::Else) {
    // TODO: handle invalid
  }
  std::ignore = ParserUtils::get_next_token();
  auto else_stmt = ParserUtils::parse_stmt_primary();
  if (else_stmt == nullptr) {
    // TODO: handle invalid
  }
  return std::make_unique<IfStmt>(std::move(bool_expr), std::move(then_stmt),
                                  std::move(else_stmt));
}