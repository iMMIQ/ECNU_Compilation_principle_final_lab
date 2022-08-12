#import "../AST/Program.h"

auto Program::code_gen() -> void {
  module->setTargetTriple("x86_64-unknown-linux-gnu");

  builder->SetInsertPoint(
      llvm::BasicBlock::Create(*context, "entry", main_func));

  for (const auto &decl : decls) {
    decl->code_gen();
  }

  // compound_stmt->code_gen();

  auto printf_func = module->getOrInsertFunction(
      "printf",
      llvm::FunctionType::get(builder->getInt32Ty(),
                              {builder->getInt8Ty()->getPointerTo()}, true));

  for (const auto &i : named_values) {
    auto *value = i.second;
    auto *format =
        builder->CreateGlobalStringPtr(i.first + ": %d\n", "format_" + i.first);
    builder->CreateCall(printf_func, {format, value});
  }
}
