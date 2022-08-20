#include "../AST/IntNumExpr.h"
#include "../AST/Program.h"

auto IntNumExpr::code_gen() -> llvm::Value * {
  return llvm::ConstantInt::get(*Program::context, llvm::APInt(32, value));
}
