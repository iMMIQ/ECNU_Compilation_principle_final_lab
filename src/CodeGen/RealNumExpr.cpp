#include "../AST/RealNumExpr.h"
#include "../AST/Program.h"

auto RealNumExpr::code_gen() -> llvm::Value * {
  return llvm::ConstantFP::get(*Program::context, llvm::APFloat(value));
}
