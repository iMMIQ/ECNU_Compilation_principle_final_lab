#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_REALDECL_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_REALDECL_H

#include "Decl.h"
#include "RealIdExpr.h"
#include "RealNumExpr.h"

class RealDecl : public Decl {
  std::unique_ptr<IdExpr> id;
  std::unique_ptr<Expr> real_num;

public:
  RealDecl(std::unique_ptr<IdExpr> id, std::unique_ptr<Expr> real_num)
      : id(std::move(id)), real_num(std::move(real_num)) {}

  auto code_gen() -> void override;

  static std::unique_ptr<Decl> parse();
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_REALDECL_H
