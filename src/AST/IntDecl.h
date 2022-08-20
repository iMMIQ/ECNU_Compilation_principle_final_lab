#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTDECL_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTDECL_H

#include "Decl.h"
#include "IntIdExpr.h"
#include "IntNumExpr.h"

class IntDecl : public Decl {
  std::unique_ptr<IdExpr> id;
  std::unique_ptr<Expr> int_num;

public:
  IntDecl(std::unique_ptr<IdExpr> id, std::unique_ptr<Expr> int_num)
      : id(std::move(id)), int_num(std::move(int_num)) {}

  auto code_gen() -> void override;

  static std::unique_ptr<Decl> parse();
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTDECL_H
