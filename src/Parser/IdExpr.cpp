#include "../AST/IdExpr.h"
#include "../AST/IntIdExpr.h"
#include "../AST/RealIdExpr.h"
#include "ParserUtils.h"

template <typename IdExprT>
std::unique_ptr<IdExprT> IdExpr::parse(std::vector<std::string> &input) {
  std::string name = std::move(Lexer::id);
  std::ignore = ParserUtils::get_next_token(input);
  return std::make_unique<IdExprT>(std::move(name));
}

template std::unique_ptr<IntIdExpr>
IdExpr::parse(std::vector<std::string> &input);

template std::unique_ptr<RealIdExpr>
IdExpr::parse(std::vector<std::string> &input);

template std::unique_ptr<IdExpr> IdExpr::parse(std::vector<std::string> &input);
