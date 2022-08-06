#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTNUMEXPR_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTNUMEXPR_H

#import "Expr.h"

class IntNumExpr : public Expr {
  int value;

public:
  explicit IntNumExpr(int value) : value(value) {}

  auto code_gen() -> llvm::Value * override;
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTNUMEXPR_H
