#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_IDEXPR_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_IDEXPR_H

#include "../Lexer/Lexer.h"
#include "../Parser/ParserUtils.h"
#include "Expr.h"

#include <string>

class IdExpr : public Expr {
protected:
  std::string name;

public:
  IdExpr(const std::string &name) : name(name) {}

  const std::string &get_name() const { return name; }

  auto code_gen() -> llvm::Value * override;

  template <typename IdExprT>
  static std::unique_ptr<IdExprT> parse(std::vector<std::string> &input);
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_IDEXPR_H
