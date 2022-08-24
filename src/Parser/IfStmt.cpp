#include "../AST/IfStmt.h"
#include "ParserUtils.h"

std::unique_ptr<Stmt> IfStmt::parse() {
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
  if (ParserUtils::get_next_token(input) != Token::Then) {
    ParserUtils::handle_invalid(input, "then");
    return nullptr;
  }
  std::ignore = ParserUtils::get_next_token();
  auto then_stmt = ParserUtils::parse_stmt_primary();
  if (then_stmt == nullptr) {
    return nullptr;
  }
  if (ParserUtils::cur_token != Token::Else) {
    ParserUtils::handle_invalid(input, "else");
    return nullptr;
  }
  std::ignore = ParserUtils::get_next_token();
  auto else_stmt = ParserUtils::parse_stmt_primary();
  if (else_stmt == nullptr) {
    return nullptr;
  }
  return std::make_unique<IfStmt>(std::move(bool_expr), std::move(then_stmt),
                                  std::move(else_stmt));
}