#include "../AST/AssgStmt.h"
#include "../AST/Program.h"
#include "Util.h"

auto AssgStmt::code_gen() -> void {
  auto *l = Program::named_values[id->get_name()];
  auto *r = arith_expr->code_gen();
  if (Util::isIntNum(l) && Util::isDoubleNum(r)) {
    r = Program::builder->CreateFPToSI(
        r, llvm::Type::getInt32Ty(*Program::context));
  } else if (Util::isDoubleNum(l) && Util::isIntNum(r)) {
    r = Program::builder->CreateSIToFP(
        r, llvm::Type::getDoubleTy(*Program::context));
  }
  Program::builder->CreateStore(r, l);
}
