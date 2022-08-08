#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_ASSGSTMT_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_ASSGSTMT_H

#import "ArithBinaryExpr.h"
#import "IdExpr.h"
#import "Stmt.h"

class AssgStmt : public Stmt {
  std::unique_ptr<IdExpr> id;
  std::unique_ptr<ArithBinaryExpr> arith_expr;

public:
  AssgStmt(std::unique_ptr<IdExpr> id,
           std::unique_ptr<ArithBinaryExpr> arith_expr)
      : id(std::move(id)), arith_expr(std::move(arith_expr)) {}

  auto code_gen() -> llvm::Value * override;
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_ASSGSTMT_H
