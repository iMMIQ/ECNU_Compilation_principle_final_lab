#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_IDEXPR_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_IDEXPR_H

#import "../Lexer/Lexer.h"
#import "../Parser/ParserUtils.h"
#import "Expr.h"

#import <string>

class IdExpr : public Expr {
protected:
  std::string name;

public:
  IdExpr(const std::string &name) : name(name) {}

  const std::string &get_name() const { return name; }

  auto code_gen() -> llvm::Value * override = 0;

  template <typename IdExprT> class parse {
  public:
    std::unique_ptr<IdExprT> operator()();
  };
};
template <typename IdExprT>
std::unique_ptr<IdExprT> IdExpr::parse<IdExprT>::operator()() {
  std::string name = std::move(Lexer::id);
  std::ignore = ParserUtils::get_next_token();
  return std::make_unique<IdExprT>(std::move(name));
}

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_IDEXPR_H
