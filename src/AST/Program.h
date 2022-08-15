#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PROGRAM_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PROGRAM_H

#import "CompoundStmt.h"
#import "Decl.h"

#import <llvm/IR/Function.h>
#import <llvm/IR/IRBuilder.h>
#import <llvm/IR/LLVMContext.h>
#import <llvm/IR/Module.h>
#import <llvm/IR/Value.h>

#import <iostream>
#import <map>
#import <memory>

class Program {
  static inline std::vector<std::unique_ptr<Decl>> decls;
  static inline std::unique_ptr<Stmt> compound_stmt;

public:
  static inline auto context = std::make_unique<llvm::LLVMContext>();
  static inline auto module =
      std::make_unique<llvm::Module>("program", *Program::context);
  static inline auto main_func = llvm::Function::Create(
      llvm::FunctionType::get(llvm::Type::getVoidTy(*Program::context), false),
      llvm::Function::ExternalLinkage, "main", *module);
  static inline auto builder =
      std::make_unique<llvm::IRBuilder<>>(*Program::context);
  static inline std::map<std::string, llvm::Value *> named_values;
  static inline std::istream *in;

  static void push_back(std::unique_ptr<Decl> decl) {
    decls.push_back(std::move(decl));
  }

  static void parse();

  static auto code_gen() -> void;
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PROGRAM_H
