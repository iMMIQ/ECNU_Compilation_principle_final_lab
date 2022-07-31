#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTDECL_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTDECL_H

#include "Decl.h"
#include "IntNumExpr.h"
class IntDecl : public Decl {
  std::unique_ptr<IntNumExpr> int_num;

public:
  IntDecl(std::unique_ptr<IdExpr> id, std::unique_ptr<IntNumExpr> int_num)
      : Decl(std::move(id)), int_num(std::move(int_num)) {}
}

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTDECL_H
