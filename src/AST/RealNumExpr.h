#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_REALNUMEXPR_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_REALNUMEXPR_H

#import "Expr.h"

class RealNumExpr : public Expr {
  double value;

public:
  explicit RealNumExpr(double value) : value(value) {}
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_REALNUMEXPR_H
