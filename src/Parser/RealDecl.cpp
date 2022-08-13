#include "../AST/RealDecl.h"
#include "ParserUtils.h"

std::unique_ptr<RealDecl> RealDecl::parse() {
  if (ParserUtils::get_next_token() != Token::ID) {
    // TODO: handle invalid
  }
  auto id = IdExpr::parse<RealIdExpr>();
  if (ParserUtils::cur_token != Token::Assignment) {
    // TODO: handle invalid
  }
  if (ParserUtils::get_next_token() != Token::IntNum) {
    // TODO: handle invalid
  }
  auto int_num = RealNumExpr::parse();
  if (ParserUtils::cur_token != Token::End) {
    // TODO: handle invalid
  }
  return std::make_unique<RealDecl>(std::move(id), std::move(int_num));
}