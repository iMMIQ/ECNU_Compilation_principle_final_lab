#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_REALDECL_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_REALDECL_H

#import "Decl.h"
#import "RealNumExpr.h"

class RealDecl : public Decl {
  std::unique_ptr<RealNumExpr> real_num;

public:
  RealDecl(std::unique_ptr<IdExpr> id, std::unique_ptr<RealNumExpr> real_num)
      : Decl(std::move(id)), real_num(std::move(real_num)) {}

  auto code_gen() -> void override;
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_REALDECL_H
