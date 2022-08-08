#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_EXPR_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_EXPR_H

#import <llvm/IR/Value.h>

class Expr {
public:
  virtual ~Expr() = default;

  virtual auto code_gen() -> llvm::Value * = 0;
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_EXPR_H
