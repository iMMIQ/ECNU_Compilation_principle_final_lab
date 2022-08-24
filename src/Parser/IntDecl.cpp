#include "../AST/IntDecl.h"
#include "ParserUtils.h"

std::unique_ptr<Decl> IntDecl::parse() {
  std::vector<std::string> input{ParserUtils::cur_input};
  if (ParserUtils::get_next_token(input) != Token::ID) {
    ParserUtils::handle_invalid(input, "an identifier");
    return nullptr;
  }
  auto id = IdExpr::parse<IntIdExpr>(input);
  if (ParserUtils::cur_token != Token::Assignment) {
    ParserUtils::handle_invalid(input, "'='");
    return nullptr;
  }
  if (ParserUtils::get_next_token(input) != Token::IntNum) {
    ParserUtils::handle_invalid(input, "an integer number");
    return nullptr;
  }
  auto int_num = IntNumExpr::parse(input);
  if (ParserUtils::cur_token != Token::End) {
    ParserUtils::handle_invalid(input, "';'");
    return nullptr;
  }
  std::ignore = ParserUtils::get_next_token();
  ParserUtils::identifiers.insert(id->get_name());
  return std::make_unique<IntDecl>(std::move(id), std::move(int_num));
}