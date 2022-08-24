#include "../AST/IntNumExpr.h"
#include "../Lexer/Lexer.h"
#include "ParserUtils.h"

std::unique_ptr<Expr> IntNumExpr::parse(std::vector<std::string> &input) {
  auto result = std::make_unique<IntNumExpr>(Lexer::int_num);
  std::ignore = ParserUtils::get_next_token(input);
  return result;
}