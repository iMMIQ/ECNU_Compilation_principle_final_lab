#import "../AST/Program.h"

auto Program::code_gen() -> void {
  module->setTargetTriple("x86_64-unknown-linux-gnu");

  builder->SetInsertPoint(
      llvm::BasicBlock::Create(*context, "entry", main_func));

  for (const auto &decl : decls) {
    decl->code_gen();
  }

  // compound_stmt->code_gen();

  auto printf_func = llvm::Function::Create(
      llvm::FunctionType::get(llvm::Type::getInt32Ty(*context),
                              {llvm::Type::getInt8PtrTy(*context)}, false),
      llvm::Function::ExternalLinkage, "printf", module.get());

  for (const auto &i : named_values) {
    llvm::Value *value = i.second;
    llvm::Value *format_str =
        llvm::ConstantDataArray::getString(*context, i.first + "： %d\n");
    llvm::Value *args[] = {format_str, value};
    builder->CreateCall(printf_func, args);
  }
}
