#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_REALIDEXPR_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_REALIDEXPR_H

#include "IdExpr.h"
class RealIdExpr : public IdExpr {
public:
  explicit RealIdExpr(const std::string &name) : IdExpr(name) {}
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_REALIDEXPR_H
