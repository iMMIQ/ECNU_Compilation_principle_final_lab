//
// Created by zzm on 22-8-9.
//

#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PARSERUTILS_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PARSERUTILS_H

#import "../Lexer/Lexer.h"

class ParserUtils {
public:
  static inline Token cur_token = Token::Error;
  static std::map<Token, int> binary_operator_precedence;
  static Token get_next_token();
  static std::map<Token, int> init_binary_operator_precedence();
  static bool is_bool_binary_operator();
  static bool is_arith_binary_operator();
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PARSERUTILS_H
