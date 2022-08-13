#import "../AST/IntDecl.h"
#import "../AST/Program.h"

auto IntDecl::code_gen() -> void {
  Program::named_values[id->get_name()] = id->code_gen();
  Program::builder->CreateStore(int_num->code_gen(),
                                Program::named_values[id->get_name()]);
}
