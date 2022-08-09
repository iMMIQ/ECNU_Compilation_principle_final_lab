#ifndef ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_DECL_H
#define ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_DECL_H

#import "IdExpr.h"

#import <memory>

class Decl {
public:
  virtual ~Decl() = default;

  virtual auto code_gen() -> void = 0;
};

#endif // ECNU_COMPILATION_PRINCIPLE_FINAL_LAB_DECL_H
