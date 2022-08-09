#import "../AST/Program.h"

auto Program::code_gen() -> void {
  for (const auto &decl : decls) {
    decl->code_gen();
  }

  compound_stmt->code_gen();

  for (const auto &i : named_values) {
    llvm::Value *value = i.second;
    llvm::Function *printf_func = module->getFunction("printf");
    llvm::Value *format_str =
        llvm::ConstantDataArray::getString(*context, i.first + "： %d\n");
    llvm::Value *args[] = {format_str, value};
    builder->CreateCall(printf_func, args);
  }
}
