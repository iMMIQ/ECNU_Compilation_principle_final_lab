#import "../AST/IntNumExpr.h"
#import "../Global.h"

auto IntNumExpr::code_gen() -> llvm::Value * {
  return llvm::ConstantInt::get(*context, llvm::APInt(32, value));
}
