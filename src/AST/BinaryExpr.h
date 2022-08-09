#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_BINARYEXPR_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_BINARYEXPR_H

#import "../Lexer/Lexer.h"
#import "Expr.h"

#import <memory>

class BinaryExpr : public Expr {
protected:
  Token op;
  std::unique_ptr<Expr> lhs, rhs;

public:
  BinaryExpr(const Token op, std::unique_ptr<Expr> lhs,
             std::unique_ptr<Expr> rhs)
      : op(op), lhs(std::move(lhs)), rhs(std::move(rhs)) {}

  ~BinaryExpr() override = default;

  auto code_gen() -> llvm::Value * override = 0;
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_BINARYEXPR_H
