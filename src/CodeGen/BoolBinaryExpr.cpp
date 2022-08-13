#import "../AST/BoolBinaryExpr.h"
#import "../AST/Program.h"

auto BoolBinaryExpr::code_gen() -> llvm::Value * {
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
    case Token::Less:
      return Program::builder->CreateICmpSLT(l, r);
    case Token::LessEqual:
      return Program::builder->CreateICmpSLE(l, r);
    case Token::Greater:
      return Program::builder->CreateICmpSGT(l, r);
    case Token::GreaterEqual:
      return Program::builder->CreateICmpSGE(l, r);
    case Token::Equal:
      return Program::builder->CreateICmpEQ(l, r);
    default:
      return nullptr;
    }
  } else {
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
}
