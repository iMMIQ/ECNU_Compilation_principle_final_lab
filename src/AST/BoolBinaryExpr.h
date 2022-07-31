#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_BOOLBINARYEXPR_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_BOOLBINARYEXPR_H

#import "BinaryExpr.h"

class BoolBinaryExpr : public BinaryExpr {
public:
  BoolBinaryExpr(char op, std::unique_ptr<Expr> lhs, std::unique_ptr<Expr> rhs)
      : BinaryExpr(op, std::move(lhs), std::move(rhs)) {}
};
#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_BOOLBINARYEXPR_H
