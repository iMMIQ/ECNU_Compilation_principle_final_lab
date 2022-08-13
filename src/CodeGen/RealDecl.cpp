#import "../AST/RealDecl.h"
#import "../AST/Program.h"

auto RealDecl::code_gen() -> void {
  Program::named_values[id->get_name()] = id->code_gen();
  Program::builder->CreateStore(real_num->code_gen(),
                                Program::named_values[id->get_name()]);
}
