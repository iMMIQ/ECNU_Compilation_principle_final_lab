#import "../AST/BoolBinaryExpr.h"
#include "ParserUtils.h"
std::unique_ptr<BoolBinaryExpr> BoolBinaryExpr::parse() {
  auto lhs = ParserUtils::parse_primary();
  if (!lhs) {
    return nullptr;
  }
  return ParserUtils::dynamic_unique_cast<BoolBinaryExpr>(
      ParserUtils::parse_binary_operator_rhs(0, std::move(lhs), 1));
}
