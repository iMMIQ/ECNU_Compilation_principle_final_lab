#import "../AST/IfStmt.h"
#import "../AST/Program.h"

auto IfStmt::code_gen() -> void {
  llvm::Value *cond = bool_expr->code_gen();
  if (!cond) {
    return;
  }

  cond = Program::builder->CreateFCmpONE(
      cond, llvm::ConstantFP::get(*Program::context, llvm::APFloat(0.0)));

  llvm::Function *func = Program::builder->GetInsertBlock()->getParent();
  llvm::BasicBlock *then_block =
      llvm::BasicBlock::Create(*Program::context, "", func);
  llvm::BasicBlock *else_block = llvm::BasicBlock::Create(*Program::context);
  llvm::BasicBlock *merge_block = llvm::BasicBlock::Create(*Program::context);

  Program::builder->CreateCondBr(cond, then_block, else_block);
  Program::builder->SetInsertPoint(then_block);
  then_stmt->code_gen();
  Program::builder->CreateBr(merge_block);
  func->getBasicBlockList().push_back(else_block);
  Program::builder->SetInsertPoint(else_block);
  else_stmt->code_gen();
  Program::builder->CreateBr(merge_block);
  func->getBasicBlockList().push_back(merge_block);
  Program::builder->SetInsertPoint(merge_block);
}
