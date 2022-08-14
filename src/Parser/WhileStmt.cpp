#include "../AST/WhileStmt.h"
#include "ParserUtils.h"
std::unique_ptr<WhileStmt> WhileStmt::parse() {
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
  std::ignore = ParserUtils::get_next_token();
  auto stmt = ParserUtils::parse_stmt_primary();
  if (stmt == nullptr) {
    // TODO: handle invalid
  }
  return std::make_unique<WhileStmt>(std::move(bool_expr), std::move(stmt));
}