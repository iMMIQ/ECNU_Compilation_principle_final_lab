#include "../AST/IntDecl.h"
#include "ParserUtils.h"

std::unique_ptr<IntDecl> IntDecl::parse() {
  if (ParserUtils::get_next_token() != Token::ID) {
    // TODO: handle invalid
  }
  auto id = IdExpr::parse();
  if (ParserUtils::get_next_token() != Token::Assignment) {
    // TODO: handle invalid
  }
  if (ParserUtils::get_next_token() != Token::IntNum) {
    // TODO: handle invalid
  }
  auto int_num = IntNumExpr::parse();
  return std::make_unique<IntDecl>(std::move(id), std::move(int_num));
}