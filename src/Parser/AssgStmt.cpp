#include "../AST/AssgStmt.h"

std::unique_ptr<Stmt> AssgStmt::parse() {
  std::vector<std::string> input{ParserUtils::cur_input};
  auto id = IdExpr::parse<IdExpr>(input);
  if (ParserUtils::cur_token != Token::Assignment) {
    ParserUtils::handle_invalid(input, "'='");
    return nullptr;
  }
  std::ignore = ParserUtils::get_next_token(input);
  auto arith_expr = ArithBinaryExpr::parse(input);
  if (arith_expr == nullptr) {
    return nullptr;
  }
  if (ParserUtils::cur_token != Token::End) {
    ParserUtils::handle_invalid(input, "';'");
    return nullptr;
  }
  std::ignore = ParserUtils::get_next_token();
  return std::make_unique<AssgStmt>(std::move(id), std::move(arith_expr));
}