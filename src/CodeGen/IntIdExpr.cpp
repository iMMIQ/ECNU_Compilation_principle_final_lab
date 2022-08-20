#include "../AST/IntIdExpr.h"
#include "../AST/Program.h"

auto IntIdExpr::code_gen() -> llvm::Value * {
  return new llvm::AllocaInst(llvm::Type::getInt32Ty(*Program::context), 0,
                              name, Program::builder->GetInsertBlock());
}