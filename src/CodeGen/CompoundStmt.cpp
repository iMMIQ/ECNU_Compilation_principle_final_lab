#import "../AST/CompoundStmt.h"

auto CompoundStmt::code_gen() -> llvm::Value * {
  llvm::Value *last;
  for (const auto &stmt : stmts) {
    last = stmt->code_gen();
  }
  return last;
}
