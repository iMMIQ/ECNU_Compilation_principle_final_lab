#import "../AST/BoolBinaryExpr.h"
#include "../AST/Program.h"

auto BoolBinaryExpr::code_gen() -> llvm::Value * {
  auto *l = lhs->code_gen();
  auto *r = rhs->code_gen();
  if (!l || !r) {
    return nullptr;
  }

  switch (op) {
  case Token::Less:
    return Program::builder->CreateFCmpOLT(l, r);
  case Token::LessEqual:
    return Program::builder->CreateFCmpOLE(l, r);
  case Token::Greater:
    return Program::builder->CreateFCmpOGT(l, r);
  case Token::GreaterEqual:
    return Program::builder->CreateFCmpOGE(l, r);
  case Token::Equal:
    return Program::builder->CreateFCmpOEQ(l, r);
  default:
    return nullptr;
  }
}
