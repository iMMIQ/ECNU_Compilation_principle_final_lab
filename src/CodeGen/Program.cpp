#import "../AST/Program.h"

auto Program::code_gen() -> void {
  module = std::make_unique<llvm::Module>("program", *context);
  builder = std::make_unique<llvm::IRBuilder<>>(*context);
  // TODO : add main function
  // function = std::make_unique<llvm::Function>(
  //      llvm::FunctionType::get(llvm::Type::getInt32Ty(*context), false),
  //      llvm::Function::ExternalLinkage, "main", module);
}
