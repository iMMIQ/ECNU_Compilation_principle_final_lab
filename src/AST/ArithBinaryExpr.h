#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_ARITHBINARYEXPR_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_ARITHBINARYEXPR_H

#import "BinaryExpr.h"

class ArithBinaryExpr : public BinaryExpr {
public:
  ArithBinaryExpr(const Token op, std::unique_ptr<Expr> lhs,
                  std::unique_ptr<Expr> rhs)
      : BinaryExpr(op, std::move(lhs), std::move(rhs)) {}

  auto code_gen() -> llvm::Value * override;

  static std::unique_ptr<ArithBinaryExpr> parse();
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_ARITHBINARYEXPR_H
