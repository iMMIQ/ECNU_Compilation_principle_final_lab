#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTNUMEXPR_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTNUMEXPR_H

#include "Expr.h"

class IntNumExpr : public Expr {
  int value;

public:
  explicit IntNumExpr(int value) : value(value) {}

  auto code_gen() -> llvm::Value * override;

  static std::unique_ptr<Expr> parse(std::vector<std::string> &input);
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTNUMEXPR_H
