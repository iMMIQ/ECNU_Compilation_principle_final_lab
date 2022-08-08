#import "../AST/ArithBinaryExpr.h"
#include "../AST/Program.h"

auto ArithBinaryExpr::code_gen() -> llvm::Value * {
  auto *l = lhs->code_gen();
  auto *r = rhs->code_gen();
  if (!l || !r) {
    return nullptr;
  }

  switch (op) {
  case '+':
    return Program::builder->CreateAdd(l, r);
  case '-':
    return Program::builder->CreateSub(l, r);
  case '*':
    return Program::builder->CreateMul(l, r);
  case '/':
    return Program::builder->CreateSDiv(l, r);
  default:
    return nullptr;
  }
}
