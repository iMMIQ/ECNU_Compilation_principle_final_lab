#include "../AST/Program.h"
#include "../AST/IntDecl.h"
#include "../AST/RealDecl.h"
#include "ParserUtils.h"

void Program::parse() {
  std::ignore = ParserUtils::get_next_token();
  bool decl_error = false;
  while (ParserUtils::cur_token != Token::Eof &&
         ParserUtils::cur_token != Token::LeftCurlyBracket) {
    if (ParserUtils::cur_token == Token::Int) {
      decl_error = false;
      auto decl = std::move(IntDecl::parse());
      if (decl) {
        Program::push_back(std::move(decl));
      }
    } else if (ParserUtils::cur_token == Token::Real) {
      decl_error = false;
      auto decl = std::move(RealDecl::parse());
      if (decl) {
        Program::push_back(std::move(decl));
      }
    } else {
      if (!decl_error) {
        std::cerr << "In Declarations, expect 'Int' or 'Real', but found '"
                  << ParserUtils::cur_input << "'." << std::endl;
        decl_error = true;
      }
    }
  }
  if (ParserUtils::cur_token == Token::Eof) {
    std::cerr << "The program ended unexpectedly." << std::endl;
  }
  compound_stmt = CompoundStmt::parse();
  if (ParserUtils::cur_token != Token::Eof) {
    std::vector<std::string> input{std::move(ParserUtils::cur_input)};
    while (ParserUtils::get_next_token(input) != Token::Eof)
      ;
    input.pop_back();
    std::cerr << "In the end of the program, unexpected '";
    std::copy(input.begin(), input.end() - 1,
              std::ostream_iterator<std::string>(std::cerr, " "));
    std::cerr << input.back() << "' occurred." << std::endl;
  }
}
