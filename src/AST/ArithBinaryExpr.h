#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_ARITHBINARYEXPR_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_ARITHBINARYEXPR_H

#include "BinaryExpr.h"

class ArithBinaryExpr : public BinaryExpr {
public:
  ArithBinaryExpr(char op, std::unique_ptr<Expr> lhs, std::unique_ptr<Expr> rhs)
      : BinaryExpr(op, std::move(lhs), std::move(rhs)) {}
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_ARITHBINARYEXPR_H
