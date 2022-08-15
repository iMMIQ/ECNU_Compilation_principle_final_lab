#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_IFSTMT_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_IFSTMT_H

#import "BoolBinaryExpr.h"
#import "Stmt.h"

class IfStmt : public Stmt {
  std::unique_ptr<Expr> bool_expr;
  std::unique_ptr<Stmt> then_stmt, else_stmt;

public:
  IfStmt(std::unique_ptr<Expr> bool_expr, std::unique_ptr<Stmt> then_stmt,
         std::unique_ptr<Stmt> else_stmt)
      : bool_expr(std::move(bool_expr)), then_stmt(std::move(then_stmt)),
        else_stmt(std::move(else_stmt)) {}

  auto code_gen() -> void override;

  static std::unique_ptr<Stmt> parse();
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_IFSTMT_H
