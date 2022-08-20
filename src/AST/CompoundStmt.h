#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_COMPOUNDSTMT_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_COMPOUNDSTMT_H

#include "Stmt.h"

#include <memory>
#include <vector>

class CompoundStmt : public Stmt {
  std::vector<std::unique_ptr<Stmt>> stmts;

public:
  CompoundStmt() = default;

  template <typename... Args> void emplace_back(Args &&...args) {
    stmts.emplace_back(std::forward<Args>(args)...);
  }

  auto code_gen() -> void override;

  static std::unique_ptr<Stmt> parse();
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_COMPOUNDSTMT_H
