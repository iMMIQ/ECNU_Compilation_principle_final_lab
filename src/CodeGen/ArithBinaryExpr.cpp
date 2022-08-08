#import "../AST/ArithBinaryExpr.h"
#include "../AST/Program.h"

auto ArithBinaryExpr::code_gen() -> llvm::Value * {
  auto *l = lhs->code_gen();
  auto *r = rhs->code_gen();
  if (!l || !r) {
    return nullptr;
  }

  switch (op) {
  case Token::Plus:
    return Program::builder->CreateAdd(l, r);
  case Token::Minus:
    return Program::builder->CreateSub(l, r);
  case Token::Multiplies:
    return Program::builder->CreateMul(l, r);
  case Token::Divides:
    return Program::builder->CreateSDiv(l, r);
  default:
    return nullptr;
  }
}
