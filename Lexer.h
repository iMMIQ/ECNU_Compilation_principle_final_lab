#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_LEXER_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_LEXER_H

#import <regex>
#import <string>
#import <vector>

using std::regex;
using std::string;
using std::vector;

enum class Token {
  // 分号
  End,
  // 标识符以字母开头，以字母或数字结尾。
  // 关键字不能是标识符，标识符的最大长度为64个字符。
  ID,
  // int
  Int,
  // 整数
  IntNum,
  // real
  Real,
  // 实数
  RealNum,
  // = 赋值
  Assignment,
  // if
  If,
  // then
  Then,
  // else
  Else,
  // 异常token
  Error
};

class Lexer {
public:
  static auto get_token();
  static string id;
  static int int_num;
  static double real_num;

private:
  using Pattern = std::pair<Token, regex>;

  // 用于正则表达式匹配
  // 注意匹配顺序
  static inline const vector<Pattern> pattern{
      {Token::Int, regex("int")},
      {Token::Real, regex("real")},
      {Token::Assignment, regex("=")},
      {Token::If, regex("if")},
      {Token::Then, regex("then")},
      {Token::Else, regex("else")},
      {Token::End, regex(";")},
      {Token::ID, regex("[a-zA-Z]([a-zA-Z0-9]){0,63}")},
      {Token::IntNum, regex("[0-9]+")},
  };
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_LEXER_H
