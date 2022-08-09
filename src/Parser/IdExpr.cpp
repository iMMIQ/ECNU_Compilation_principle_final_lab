#include "../AST/IdExpr.h"
#include "../Lexer/Lexer.h"
#include "ParserUtils.h"

std::unique_ptr<IdExpr> IdExpr::parse() {
  std::string name = std::move(Lexer::id);
  std::ignore = ParserUtils::get_next_token();
  return std::make_unique<IdExpr>(std::move(name));
}