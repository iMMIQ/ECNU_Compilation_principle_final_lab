#import "../AST/ArithBinaryExpr.h"
#import "../AST/Program.h"
#include "Util.h"

auto ArithBinaryExpr::code_gen() -> llvm::Value * {
  auto *l = lhs->code_gen();
  auto *r = rhs->code_gen();
  if (!l || !r) {
    return nullptr;
  }

  if (l->getType()->isPointerTy()) {
    if (Util::isIntNum(l)) {
      l = Program::builder->CreateLoad(
          llvm::Type::getInt32Ty(*Program::context), l);
    } else {
      l = Program::builder->CreateLoad(
          llvm::Type::getDoubleTy(*Program::context), l);
    }
  }

  if (r->getType()->isPointerTy()) {
    if (Util::isIntNum(r)) {
      r = Program::builder->CreateLoad(
          llvm::Type::getInt32Ty(*Program::context), r);
    } else {
      r = Program::builder->CreateLoad(
          llvm::Type::getDoubleTy(*Program::context), r);
    }
  }

  if (Util::isIntNum(l) && Util::isDoubleNum(r)) {
    l = Program::builder->CreateSIToFP(
        l, llvm::Type::getDoubleTy(*Program::context));
  } else if (Util::isDoubleNum(l) && Util::isIntNum(r)) {
    r = Program::builder->CreateSIToFP(
        r, llvm::Type::getDoubleTy(*Program::context));
  }

  if (Util::isIntNum(l)) {
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
