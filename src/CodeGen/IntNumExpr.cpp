#import "../AST/IntNumExpr.h"
#import "../AST/Program.h"

auto IntNumExpr::code_gen() -> llvm::Value * {
  return llvm::ConstantInt::get(*Program::context, llvm::APInt(32, value));
}
