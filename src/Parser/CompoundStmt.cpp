#include "../AST/CompoundStmt.h"
#include "ParserUtils.h"

std::unique_ptr<Stmt> CompoundStmt::parse() {
  int ret = 0;
  std::ignore = ParserUtils::get_next_token();
  CompoundStmt result;
  while (ParserUtils::cur_token != Token::RightCurlyBracket &&
         ParserUtils::cur_token != Token::Eof) {
    auto stmt = ParserUtils::parse_stmt_primary();
    if (stmt == nullptr) {
      std::ignore = ParserUtils::get_next_token();
      ret = 1;
      continue;
    }
    result.emplace_back(std::move(stmt));
  }
  if (ParserUtils::cur_token == Token::Eof) {
    ParserUtils::handle_eof();
    return nullptr;
  }
  std::ignore = ParserUtils::get_next_token();
  if (ret) {
    return nullptr;
  }
  return std::make_unique<CompoundStmt>(std::move(result));
}