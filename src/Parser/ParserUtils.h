//
// Created by zzm on 22-8-9.
//

#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PARSERUTILS_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PARSERUTILS_H

#import "../Lexer/Lexer.h"

class ParserUtils {
public:
  static inline Token cur_token = Token::Error;
  static Token get_next_token();
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PARSERUTILS_H
