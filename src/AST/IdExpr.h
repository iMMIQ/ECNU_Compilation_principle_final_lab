#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_IDEXPR_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_IDEXPR_H

#import "Expr.h"

#import <string>

class IdExpr : public Expr {
  std::string name;

public:
  IdExpr(const std::string &name) : name(name) {}

  const std::string &get_name() const { return name; }

  auto code_gen() -> llvm::Value * override;
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_IDEXPR_H
