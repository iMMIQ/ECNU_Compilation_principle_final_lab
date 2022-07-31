#import <iostream>
#import <regex>
#import <string>
#import <vector>

using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::string;

enum class Token { End, ID, Int, IntNum, Real, RealNum, If, Then, Else, Error };

using Pattern = std::pair<Token, regex>;

// 用于正则表达式匹配
// 注意匹配顺序
std::vector<Pattern> pattern{
    {Token::Int, regex("int")},
    {Token::Real, regex("real")},
    {Token::If, regex("if")},
    {Token::Then, regex("then")},
    {Token::Else, regex("else")},
    {Token::ID, regex("[a-zA-Z]([a-zA-Z0-9]){0,63}")},
    {Token::IntNum, regex("[0-9]+")},
};

// 标识符以字母开头，以字母或数字结尾。 关键字不能是标识符，标识符的最大长度为
// 64 个字符。
static string id;

// 整数
static int int_num;

// 实数
static double real_num;

auto get_token() {
  char last_char = static_cast<char>(getchar());
  while (std::isspace(last_char)) {
    last_char = static_cast<char>(getchar());
  }
  string s;
  do {
    if (last_char == ';') {
      return Token::End;
    }
    s += last_char;
    last_char = static_cast<char>(getchar());
  } while (!std::isspace(last_char));

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