#include "ParserUtils.h"

std::map<Token, int> ParserUtils::binary_operator_precedence =
    init_binary_operator_precedence();

Token ParserUtils::get_next_token() { return cur_token = Lexer::get_token(); }

std::map<Token, int> ParserUtils::init_binary_operator_precedence() {
  std::map<Token, int> ret;
  ret[Token::Less] = 10;
  ret[Token::LessEqual] = 10;
  ret[Token::Greater] = 10;
  ret[Token::GreaterEqual] = 10;
  ret[Token::Equal] = 10;
  ret[Token::Plus] = 20;
  ret[Token::Minus] = 20;
  ret[Token::Multiplies] = 40;
  ret[Token::Divides] = 40;
  return ret;
}
bool ParserUtils::is_bool_binary_operator() {
  return cur_token == Token::Less || cur_token == Token::LessEqual ||
         cur_token == Token::Greater || cur_token == Token::GreaterEqual ||
         cur_token == Token::Equal;
}
bool ParserUtils::is_arith_binary_operator() {
  return cur_token == Token::Plus || cur_token == Token::Minus ||
         cur_token == Token::Multiplies || cur_token == Token::Divides;
}
