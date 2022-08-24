#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_BOOLBINARYEXPR_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_BOOLBINARYEXPR_H

#include "BinaryExpr.h"

class BoolBinaryExpr : public BinaryExpr {
public:
  BoolBinaryExpr(const Token op, std::unique_ptr<Expr> lhs,
                 std::unique_ptr<Expr> rhs)
      : BinaryExpr(op, std::move(lhs), std::move(rhs)) {}

  auto code_gen() -> llvm::Value * override;

  static std::unique_ptr<Expr> parse(std::vector<std::string> &input);
};
#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_BOOLBINARYEXPR_H
