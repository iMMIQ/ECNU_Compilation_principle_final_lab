#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_REALNUMEXPR_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_REALNUMEXPR_H

#include "Expr.h"

class RealNumExpr : public Expr {
  double value;

public:
  explicit RealNumExpr(double value) : value(value) {}

  auto code_gen() -> llvm::Value * override;

  static std::unique_ptr<Expr> parse(std::vector<std::string> &input);
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_REALNUMEXPR_H
