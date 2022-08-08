#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_STMT_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_STMT_H

#import <llvm/IR/Value.h>

class Stmt {
public:
  virtual ~Stmt() = default;

  virtual auto code_gen() -> llvm::Value * = 0;
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_STMT_H
