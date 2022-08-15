//
// Created by zzm on 22-8-9.
//

#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PARSERUTILS_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PARSERUTILS_H

#include "../AST/Expr.h"
#include "../AST/Stmt.h"
#import "../Lexer/Lexer.h"

class ParserUtils {
public:
  static inline Token cur_token = Token::Error;
  static std::map<Token, int> binary_operator_precedence;
  static Token get_next_token();
  static std::map<Token, int> init_binary_operator_precedence();
  static bool is_bool_binary_operator(Token cur_token);
  static bool is_arith_binary_operator(Token cur_token);
  static int get_token_precedence(Token cur_token);
  static std::unique_ptr<Expr> parse_expr_paren();
  static std::unique_ptr<Expr> parse_expr_primary();
  static std::unique_ptr<Expr>
  parse_binary_operator_rhs(int expr_prec, std::unique_ptr<Expr> lhs,
                            int bool_binary_operator_counter);
  static std::unique_ptr<Stmt> parse_stmt_primary();
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PARSERUTILS_H
