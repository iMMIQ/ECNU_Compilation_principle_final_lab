#include "../AST/RealNumExpr.h"
#include "../Lexer/Lexer.h"
#include "ParserUtils.h"

std::unique_ptr<RealNumExpr> RealNumExpr::parse() {
  auto result = std::make_unique<RealNumExpr>(Lexer::int_num);
  std::ignore = ParserUtils::get_next_token();
  return result;
}