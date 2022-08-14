#import "../AST/WhileStmt.h"
#import "../AST/Program.h"

auto WhileStmt::code_gen() -> void {
  auto func = Program::builder->GetInsertBlock()->getParent();
  auto check_block = llvm::BasicBlock::Create(*Program::context, "", func);
  auto loop_block = llvm::BasicBlock::Create(*Program::context, "", func);
  auto after_block = llvm::BasicBlock::Create(*Program::context, "", func);

  Program::builder->CreateBr(check_block);
  Program::builder->SetInsertPoint(check_block);

  auto cond_val = bool_expr->code_gen();
  Program::builder->CreateCondBr(cond_val, loop_block, after_block);

  Program::builder->SetInsertPoint(loop_block);
  stmt->code_gen();
  Program::builder->CreateBr(check_block);

  Program::builder->SetInsertPoint(after_block);
}
