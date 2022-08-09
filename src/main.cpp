#import "AST/Program.h"

int main(int argc, char **argv) {
  Program::in = &std::cin;
  Program::parse();
  Program::code_gen();
  Program::module->print(llvm::errs(), nullptr);
  std::istream *input;
  return 0;
}