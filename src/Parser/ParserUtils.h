#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PARSERUTILS_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PARSERUTILS_H

#include "../AST/Expr.h"
#include "../AST/Stmt.h"
#include "../Lexer/Lexer.h"
#include <set>
#include <string>

class ParserUtils {
public:
  static inline Token cur_token = Token::Error;
  static inline std::string cur_input;
  static inline bool error = false;
  static inline bool recoverable_error = false;
  static std::map<Token, int> binary_operator_precedence;
  static inline std::set<std::string> identifiers;
  static Token get_next_token(std::vector<std::string> &input);
  static Token get_next_token();
  static std::map<Token, int> init_binary_operator_precedence();
  static bool is_bool_binary_operator(Token cur_token);
  static bool is_arith_binary_operator(Token cur_token);
  static int get_token_precedence(Token cur_token);
  static std::unique_ptr<Expr>
  parse_expr_paren(std::vector<std::string> &input);
  static std::unique_ptr<Expr>
  parse_expr_primary(std::vector<std::string> &input);
  static std::unique_ptr<Expr>
  parse_binary_operator_rhs(int expr_prec, std::unique_ptr<Expr> lhs,
                            int bool_binary_operator_counter,
                            std::vector<std::string> &input);
  static std::unique_ptr<Stmt> parse_stmt_primary();
  static void handle_invalid(const std::vector<std::string> &input,
                             const std::string &expected);
  static void handle_eof();
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PARSERUTILS_H
