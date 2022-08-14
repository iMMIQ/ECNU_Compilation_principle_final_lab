#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_WHILESTMT_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_WHILESTMT_H

#include "BoolBinaryExpr.h"
#include "Stmt.h"
class WhileStmt : public Stmt {
  std::unique_ptr<BoolBinaryExpr> bool_expr;
  std::unique_ptr<Stmt> stmt;

public:
  WhileStmt(std::unique_ptr<BoolBinaryExpr> bool_expr,
            std::unique_ptr<Stmt> stmt)
      : bool_expr(std::move(bool_expr)), stmt(std::move(stmt)) {}

  auto code_gen() -> void override;
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_WHILESTMT_H
