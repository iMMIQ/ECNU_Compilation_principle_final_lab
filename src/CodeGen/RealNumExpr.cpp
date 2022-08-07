#import "../AST/RealNumExpr.h"
#import "Global.h"

auto RealNumExpr::code_gen() -> llvm::Value * {
  return llvm::ConstantFP::get(*Global::context, llvm::APFloat(value));
}
