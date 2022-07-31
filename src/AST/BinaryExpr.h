#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_BINARYEXPR_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_BINARYEXPR_H

#import "Expr.h"

#import <memory>

class BinaryExpr : public Expr {
protected:
  char op;
  std::unique_ptr<Expr> lhs, rhs;

  BinaryExpr(const char op, std::unique_ptr<Expr> lhs,
             std::unique_ptr<Expr> rhs)
      : op(op), lhs(std::move(lhs)), rhs(std::move(rhs)) {}
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_BINARYEXPR_H
