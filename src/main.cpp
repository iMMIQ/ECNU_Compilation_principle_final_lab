#import "AST/Program.h"

int main() {
  Program::code_gen();
  Program::module->print(llvm::errs(), nullptr);
  return 0;
}