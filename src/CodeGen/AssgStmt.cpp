#import "../AST/AssgStmt.h"
#import "../AST/Program.h"

auto AssgStmt::code_gen() -> void {
  Program::builder->CreateStore(arith_expr->code_gen(),
                                Program::named_values[id->get_name()]);
}
