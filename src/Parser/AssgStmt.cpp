#include "../AST/AssgStmt.h"
std::unique_ptr<Stmt> AssgStmt::parse() {
  auto id = IdExpr::parse<IdExpr>();
  if (ParserUtils::cur_token != Token::Assignment) {
    // TODO: handle invalid
  }
  std::ignore = ParserUtils::get_next_token();
  auto arith_expr = ArithBinaryExpr::parse();
  if (arith_expr == nullptr) {
    // TODO: handle invalid
  }
  if (ParserUtils::cur_token != Token::End) {
    // TODO: handle invalid
  }
  std::ignore = ParserUtils::get_next_token();
  return std::make_unique<AssgStmt>(std::move(id), std::move(arith_expr));
}