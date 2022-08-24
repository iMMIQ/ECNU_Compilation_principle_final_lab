#include "../AST/WhileStmt.h"
#include "ParserUtils.h"

std::unique_ptr<Stmt> WhileStmt::parse() {
  std::vector<std::string> input{ParserUtils::cur_input};
  if (ParserUtils::get_next_token(input) != Token::LeftRoundBracket) {
    ParserUtils::handle_invalid(input, "'('");
    return nullptr;
  }
  std::ignore = ParserUtils::get_next_token(input);
  auto bool_expr = BoolBinaryExpr::parse(input);
  if (bool_expr == nullptr) {
    return nullptr;
  }
  if (ParserUtils::cur_token != Token::RightRoundBracket) {
    ParserUtils::handle_invalid(input, "')'");
    return nullptr;
  }
  std::ignore = ParserUtils::get_next_token();
  auto stmt = ParserUtils::parse_stmt_primary();
  if (stmt == nullptr) {
    return nullptr;
  }
  return std::make_unique<WhileStmt>(std::move(bool_expr), std::move(stmt));
}