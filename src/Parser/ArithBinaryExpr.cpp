#include "../AST/ArithBinaryExpr.h"
#include "ParserUtils.h"

std::unique_ptr<Expr> ArithBinaryExpr::parse(std::vector<std::string> &input) {
  auto lhs = ParserUtils::parse_expr_primary(input);
  if (!lhs) {
    return nullptr;
  }
  return ParserUtils::parse_binary_operator_rhs(0, std::move(lhs), 0, input);
}