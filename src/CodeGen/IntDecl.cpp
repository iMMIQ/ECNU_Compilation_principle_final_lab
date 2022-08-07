#import "../AST/IntDecl.h"
#import "Global.h"

auto IntDecl::code_gen() -> void {
  Global::named_values[id->get_name()] = int_num->code_gen();
}
