#import "../AST/RealDecl.h"
#import "../AST/Program.h"

auto RealDecl::code_gen() -> void {
  Program::named_values[id->get_name()] = real_num->code_gen();
}
