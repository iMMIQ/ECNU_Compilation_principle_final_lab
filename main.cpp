#import <iostream>
#import <regex>
#import <string>
#import <vector>

using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::string;

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

using Pattern = std::pair<Token, regex>;

// 用于正则表达式匹配
// 注意匹配顺序
std::vector<Pattern> pattern{
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

static string id;
static int int_num;
static double real_num;

auto get_token() {
  string s;
  cin >> s;

  for (const auto &p : pattern) {
    if (std::regex_match(s, p.second)) {
      if (p.first == Token::ID) {
        std::swap(id, s);
      } else if (p.first == Token::IntNum) {
        int_num = std::stoi(s);
      }
      return p.first;
    }
  }
  return Token::Error;
}

int main() {
  cout << "hello, world!" << endl;
  return 0;
}