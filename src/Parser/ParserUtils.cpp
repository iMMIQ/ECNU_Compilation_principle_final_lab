#include "ParserUtils.h"

Token ParserUtils::get_next_token() { return cur_token = Lexer::get_token(); }
