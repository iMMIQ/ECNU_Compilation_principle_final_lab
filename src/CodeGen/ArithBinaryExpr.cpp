#import "../AST/ArithBinaryExpr.h"
#import "../AST/Program.h"

auto ArithBinaryExpr::code_gen() -> llvm::Value * {
  auto *l = lhs->code_gen();
  auto *r = rhs->code_gen();
  if (!l || !r) {
    return nullptr;
  }
  if (l->getType()->getPointerElementType()->isIntegerTy() &&
      r->getType()->getPointerElementType()->isDoubleTy()) {
    l = Program::builder->CreateBitCast(
        l, llvm::Type::getDoubleTy(*Program::context));
  } else if (r->getType()->getPointerElementType()->isIntegerTy() &&
             l->getType()->getPointerElementType()->isDoubleTy()) {
    r = Program::builder->CreateBitCast(
        r, llvm::Type::getDoubleTy(*Program::context));
  }

  if (l->getType()->getPointerElementType()->isIntegerTy()) {
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
  } else {
    switch (op) {
    case Token::Plus:
      return Program::builder->CreateFAdd(l, r);
    case Token::Minus:
      return Program::builder->CreateFSub(l, r);
    case Token::Multiplies:
      return Program::builder->CreateFMul(l, r);
    case Token::Divides:
      return Program::builder->CreateFDiv(l, r);
    default:
      return nullptr;
    }
  }
}
