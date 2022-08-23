#include "../AST/RealDecl.h"
#include "ParserUtils.h"

std::unique_ptr<Decl> RealDecl::parse() {
  std::vector<std::string> input{ParserUtils::cur_input};
  if (ParserUtils::get_next_token() != Token::ID) {
    ParserUtils::handle_invalid(input, "an identifier");
    return nullptr;
  }
  auto id = IdExpr::parse<RealIdExpr>();
  if (ParserUtils::cur_token != Token::Assignment) {
    ParserUtils::handle_invalid(input, "'='");
    return nullptr;
  }
  if (ParserUtils::get_next_token() != Token::RealNum) {
    ParserUtils::handle_invalid(input, "an real number");
    return nullptr;
  }
  auto real_num = RealNumExpr::parse();
  if (ParserUtils::cur_token != Token::End) {
    ParserUtils::handle_invalid(input, "';'");
    return nullptr;
  }
  std::ignore = ParserUtils::get_next_token();
  return std::make_unique<RealDecl>(std::move(id), std::move(real_num));
}