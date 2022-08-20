#include "../AST/BoolBinaryExpr.h"
#include "../AST/Program.h"
#include "Util.h"

auto BoolBinaryExpr::code_gen() -> llvm::Value * {
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
