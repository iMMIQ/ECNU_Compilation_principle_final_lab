#include "Lexer.h"
#include "../AST/Program.h"

Token Lexer::get_token() {
  string s;
  if (!(*Program::in >> s)) {
    return Token::Eof;
  }

  for (const auto &p : pattern) {
    if (std::regex_match(s, p.second)) {
      if (p.first == Token::ID) {
        std::swap(id, s);
      } else if (p.first == Token::IntNum) {
        int_num = std::stoi(s);
      } else if (p.first == Token::RealNum) {
        real_num = std::stod(s);
      }
      return p.first;
    }
  }

  llvm::errs() << "Unknown token: " << s << "\n";
  return Token::Error;
}
