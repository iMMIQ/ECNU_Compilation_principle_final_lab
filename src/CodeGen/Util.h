#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_UTIL_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_UTIL_H

#include <llvm/IR/Value.h>

namespace Util {
auto isIntNum(llvm::Value *v) -> bool;
auto isDoubleNum(llvm::Value *v) -> bool;
}; // namespace Util

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_UTIL_H
