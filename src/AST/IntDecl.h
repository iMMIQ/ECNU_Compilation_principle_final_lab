#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTDECL_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTDECL_H

#import "Decl.h"
#include "IntIdExpr.h"
#import "IntNumExpr.h"

class IntDecl : public Decl {
  std::unique_ptr<IntIdExpr> id;
  std::unique_ptr<IntNumExpr> int_num;

public:
  IntDecl(std::unique_ptr<IntIdExpr> id, std::unique_ptr<IntNumExpr> int_num)
      : id(std::move(id)), int_num(std::move(int_num)) {}

  auto code_gen() -> void override;

  static std::unique_ptr<IntDecl> parse();
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTDECL_H
