#import <iostream>
#import <map>
#import <regex>
#import <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

enum class Token { Eof, ID, Int, IntNum, Real, RealNum, If, Then, Else, Error };

std::map<Token, std::regex> pattern{
    {Token::ID, std::regex("[a-zA-Z]([a-zA-Z0-9]){0,63}")},
    {Token::IntNum, std::regex("[0-9]+")}};

// 标识符以字母开头，以字母或数字结尾。 关键字不能是标识符，标识符的最大长度为
// 64 个字符。
// [a-zA-Z][a-zA-Z0-9]{0,63}
static string id;

// 整数 [0-9]+
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
    s += last_char;
    last_char = static_cast<char>(getchar());
  } while (!std::isspace(last_char));

  for (const auto &p : pattern) {
    if (std::regex_match(s, p.second)) {
      if (p.first == Token::ID) {
        id = std::move(s);
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