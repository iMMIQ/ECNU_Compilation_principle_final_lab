#include "../AST/IdExpr.h"
#include "../Lexer/Lexer.h"
#include "ParserUtils.h"

template <typename IdExprT> std::unique_ptr<IdExprT> IdExpr::parse() {
  std::string name = std::move(Lexer::id);
  std::ignore = ParserUtils::get_next_token();
  return std::make_unique<IdExprT>(std::move(name));
}