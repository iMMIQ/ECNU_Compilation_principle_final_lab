#import "../AST/IntDecl.h"
#import "../AST/Program.h"

auto IntDecl::code_gen() -> void {
  Program::named_values[id->get_name()] = int_num->code_gen();
}
