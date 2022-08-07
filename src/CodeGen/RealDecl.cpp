#import "../AST/RealDecl.h"
#import "Global.h"

auto RealDecl::code_gen() -> void {
  Global::named_values[id->get_name()] = real_num->code_gen();
}
