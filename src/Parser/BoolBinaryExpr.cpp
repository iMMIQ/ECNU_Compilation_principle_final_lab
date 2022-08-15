#import "../AST/BoolBinaryExpr.h"
#include "ParserUtils.h"
std::unique_ptr<Expr> BoolBinaryExpr::parse() {
  auto lhs = ParserUtils::parse_expr_primary();
  if (!lhs) {
    return nullptr;
  }
  return ParserUtils::parse_binary_operator_rhs(0, std::move(lhs), 1);
}
