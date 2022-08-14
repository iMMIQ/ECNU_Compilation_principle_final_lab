#include "../AST/CompoundStmt.h"
#include "ParserUtils.h"
std::unique_ptr<CompoundStmt> CompoundStmt::parse() {
  std::ignore = ParserUtils::get_next_token();
  CompoundStmt result;
  while (ParserUtils::cur_token != Token::RightCurlyBracket) {
    auto stmt = ParserUtils::parse_stmt_primary();
    if (stmt == nullptr) {
      // TODO: handle invalid
    }
    result.emplace_back(std::move(stmt));
  }
  return std::make_unique<CompoundStmt>(std::move(result));
}