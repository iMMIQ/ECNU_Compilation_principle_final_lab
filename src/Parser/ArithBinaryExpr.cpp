#include "../AST/ArithBinaryExpr.h"
#include "ParserUtils.h"
std::unique_ptr<ArithBinaryExpr> ArithBinaryExpr::parse() {
  auto lhs = ParserUtils::parse_primary();
  if (!lhs) {
    return nullptr;
  }
  return ParserUtils::dynamic_unique_cast<ArithBinaryExpr>(
      ParserUtils::parse_binary_operator_rhs(0, std::move(lhs), 0));
}