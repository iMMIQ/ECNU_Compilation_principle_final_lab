#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTIDEXPR_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTIDEXPR_H

#include "IdExpr.h"
class IntIdExpr : public IdExpr {
public:
  explicit IntIdExpr(const std::string &name) : IdExpr(name) {}
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_INTIDEXPR_H
