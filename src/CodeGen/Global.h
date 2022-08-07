#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_GLOBAL_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_GLOBAL_H

#import <llvm/IR/IRBuilder.h>
#import <llvm/IR/LLVMContext.h>
#import <llvm/IR/Module.h>
#import <llvm/IR/Value.h>

#import <map>
#import <memory>

namespace Global {
static std::unique_ptr<llvm::LLVMContext> context;
static std::unique_ptr<llvm::Module> module;
static std::unique_ptr<llvm::IRBuilder<>> builder;
static std::map<std::string, llvm::Value *> named_values;
} // namespace Global

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_GLOBAL_H
