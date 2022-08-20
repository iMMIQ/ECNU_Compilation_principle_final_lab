#include "../AST/IdExpr.h"
#include "../AST/Program.h"

auto IdExpr::code_gen() -> llvm::Value * { return Program::named_values[name]; }
