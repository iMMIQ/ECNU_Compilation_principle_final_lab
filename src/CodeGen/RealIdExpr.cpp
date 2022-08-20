#include "../AST/RealIdExpr.h"
#include "../AST/Program.h"

auto RealIdExpr::code_gen() -> llvm::Value * {
  return new llvm::AllocaInst(llvm::Type::getDoubleTy(*Program::context), 0,
                              name, Program::builder->GetInsertBlock());
}