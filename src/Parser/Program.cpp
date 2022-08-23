#include "../AST/Program.h"
#include "../AST/IntDecl.h"
#include "../AST/RealDecl.h"
#include "ParserUtils.h"

int Program::parse() {
  int ret = 0;
  std::ignore = ParserUtils::get_next_token();
  while (ParserUtils::cur_token != Token::Eof &&
         ParserUtils::cur_token != Token::LeftCurlyBracket) {
    if (ParserUtils::cur_token == Token::Int) {
      ParserUtils::error = false;
      auto decl = IntDecl::parse();
      if (decl) {
        Program::push_back(std::move(decl));
      } else {
        ret = 1;
      }
    } else if (ParserUtils::cur_token == Token::Real) {
      ParserUtils::error = false;
      auto decl = RealDecl::parse();
      if (decl) {
        Program::push_back(std::move(decl));
      } else {
        ret = 1;
      }
    } else {
      if (!ParserUtils::error) {
        std::cerr << "In Declarations, expect 'Int' or 'Real', but found '"
                  << ParserUtils::cur_input << "'." << std::endl;
        ParserUtils::error = true;
        ret = 1;
      }
    }
  }
  ParserUtils::error = false;
  if (ParserUtils::cur_token == Token::Eof) {
    std::cerr << "The program ended unexpectedly." << std::endl;
    ret = 1;
  }
  compound_stmt = CompoundStmt::parse();
  if (!compound_stmt) {
    ret = 1;
  }
  if (ParserUtils::cur_token != Token::Eof) {
    std::vector<std::string> input{std::move(ParserUtils::cur_input)};
    while (ParserUtils::get_next_token(input) != Token::Eof)
      ;
    input.pop_back();
    std::cerr << "In the end of the program, unexpected '";
    std::copy(input.begin(), input.end() - 1,
              std::ostream_iterator<std::string>(std::cerr, " "));
    std::cerr << input.back() << "' occurred." << std::endl;
    ret = 1;
  }
  return ret;
}
