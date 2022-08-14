#include "../AST/AssgStmt.h"
#include "../AST/IntIdExpr.h"
#include "../AST/RealIdExpr.h"
std::unique_ptr<AssgStmt> AssgStmt::parse() {
  std::unique_ptr<IdExpr> id;
  if (ParserUtils::cur_token == Token::Int) {
    id = IdExpr::parse<IntIdExpr>();
  } else {
    id = IdExpr::parse<RealIdExpr>();
  }
  if (ParserUtils::get_next_token() != Token::Assignment) {
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