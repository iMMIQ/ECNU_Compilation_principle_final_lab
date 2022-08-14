#import "../AST/IfStmt.h"
#import "../AST/Program.h"

auto IfStmt::code_gen() -> void {
  llvm::Value *cond = bool_expr->code_gen();
  if (!cond) {
    return;
  }

  llvm::Function *func = Program::builder->GetInsertBlock()->getParent();
  llvm::BasicBlock *then_block =
      llvm::BasicBlock::Create(*Program::context, "", func);
  llvm::BasicBlock *else_block =
      llvm::BasicBlock::Create(*Program::context, "", func);
  llvm::BasicBlock *merge_block =
      llvm::BasicBlock::Create(*Program::context, "", func);

  Program::builder->CreateCondBr(cond, then_block, else_block);

  Program::builder->SetInsertPoint(then_block);
  then_stmt->code_gen();
  Program::builder->CreateBr(merge_block);

  Program::builder->SetInsertPoint(else_block);
  else_stmt->code_gen();
  Program::builder->CreateBr(merge_block);

  Program::builder->SetInsertPoint(merge_block);
}
