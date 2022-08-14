#include "Util.h"

#include "llvm/IR/Type.h"

auto Util::isIntNum(llvm::Value *v) -> bool {
  if (v->getType()->isIntegerTy()) {
    return true;
  } else if (v->getType()->isPointerTy()) {
    return v->getType()->getPointerElementType()->isIntegerTy();
  }
  return false;
}

auto Util::isDoubleNum(llvm::Value *v) -> bool {
  if (v->getType()->isDoubleTy()) {
    return true;
  } else if (v->getType()->isPointerTy()) {
    return v->getType()->getPointerElementType()->isDoubleTy();
  }
  return false;
}
