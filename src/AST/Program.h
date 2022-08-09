#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PROGRAM_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PROGRAM_H

#import "CompoundStmt.h"
#import "Decl.h"

#import <llvm/IR/Function.h>
#import <llvm/IR/IRBuilder.h>
#import <llvm/IR/LLVMContext.h>
#import <llvm/IR/Module.h>
#import <llvm/IR/Value.h>

#import <map>
#import <memory>

class Program {
  static inline std::vector<std::unique_ptr<Decl>> decls;
  static inline std::unique_ptr<CompoundStmt> compound_stmt;

public:
  static inline auto context = std::make_unique<llvm::LLVMContext>();
  static inline auto module =
      std::make_unique<llvm::Module>("program", *Program::context);
  static inline auto main_func = llvm::Function::Create(
      llvm::FunctionType::get(llvm::Type::getInt32Ty(*Program::context), false),
      llvm::Function::ExternalLinkage, "main", *module);
  static inline auto builder =
      std::make_unique<llvm::IRBuilder<>>(*Program::context);
  static inline std::map<std::string, llvm::Value *> named_values;

  template <typename... Args> static void emplace_back(Args &&...args) {
    decls.emplace_back(std::forward<Args>(args)...);
  }

  static void set_compound_stmt(std::unique_ptr<CompoundStmt> _compound_stmt) {
    swap(Program::compound_stmt, _compound_stmt);
  }

  static auto code_gen() -> void;
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PROGRAM_H
