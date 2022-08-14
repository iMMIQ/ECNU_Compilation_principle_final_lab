#include "../AST/Program.h"
#include "../AST/IntDecl.h"
#include "../AST/RealDecl.h"
#include "ParserUtils.h"

void Program::parse() {
  std::ignore = ParserUtils::get_next_token();
  while (ParserUtils::cur_token == Token::Int ||
         ParserUtils::cur_token == Token::Real) {
    if (ParserUtils::cur_token == Token::Int) {
      auto decl = std::move(IntDecl::parse());
      if (decl) {
        Program::push_back(std::move(decl));
      }
    } else {
      auto decl = std::move(RealDecl::parse());
      if (decl) {
        Program::push_back(std::move(decl));
      }
    }
  }
  if (ParserUtils::cur_token != Token::LeftCurlyBracket) {
    // TODO: handle invalid
  }
  compound_stmt = CompoundStmt::parse();
}