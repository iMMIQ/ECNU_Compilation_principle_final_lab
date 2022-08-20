#include "PreLexer.h"

#include <vector>

auto PreLexer::addSpace(std::string &s) -> void {
  const std::vector<std::string> token{";", "<=", "==", ">=", "+",
                                       "-", "*",  "/",  "(",  ")",
                                       "{", "}",  "<",  ">",  "="};
  for (const auto &t : token) {
    int pos = s.find(t);
    while (pos != std::string::npos) {
      if ((pos == 0 ||
           (s[pos - 1] != '=' && s[pos - 1] != '<' && s[pos - 1] != '>')) &&
          (pos == s.length() - t.length() || s[pos + t.length()] != '=')) {
        if (pos == 0) {
          s.insert(pos + t.length(), " ");
          s.insert(s.begin(), ' ');
        } else {
          s.insert(pos, " ");
          s.insert(pos + t.length() + 1, " ");
        }
      }
      pos = s.find(t, pos + t.length() + 1);
    }
  }
}
