#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_ASSGSTMT_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_ASSGSTMT_H

#include "ArithBinaryExpr.h"
#include "IdExpr.h"
#include "Stmt.h"

class AssgStmt : public Stmt {
  std::unique_ptr<IdExpr> id;
  std::unique_ptr<Expr> arith_expr;

public:
  AssgStmt(std::unique_ptr<IdExpr> id, std::unique_ptr<Expr> arith_expr)
      : id(std::move(id)), arith_expr(std::move(arith_expr)) {}

  auto code_gen() -> void override;

  static std::unique_ptr<Stmt> parse();
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_ASSGSTMT_H
