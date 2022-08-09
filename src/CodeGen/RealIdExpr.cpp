#import "../AST/RealIdExpr.h"
#import "../AST/Program.h"

auto RealIdExpr::code_gen() -> llvm::Value * {
  return new llvm::AllocaInst(llvm::Type::getDoubleTy(*Program::context), 0,
                              name, Program::builder->GetInsertBlock());
}