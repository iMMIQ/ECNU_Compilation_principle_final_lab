#import "../AST/CompoundStmt.h"

auto CompoundStmt::code_gen() -> void {
  for (const auto &stmt : stmts) {
    stmt->code_gen();
  }
}
