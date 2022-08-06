#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PROGRAM_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PROGRAM_H

#include "CompoundStmt.h"
#include "Decl.h"

class Program {
  static std::vector<std::unique_ptr<Decl>> decls;
  static std::unique_ptr<CompoundStmt> compound_stmt;

public:
  template <typename... Args> static void emplace_back(Args &&...args) {
    decls.emplace_back(std::forward<Args>(args)...);
  }

  static void set_compound_stmt(std::unique_ptr<CompoundStmt> compound_stmt) {
    swap(Program::compound_stmt, compound_stmt);
  }

  static auto code_gen() -> void;
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_PROGRAM_H
