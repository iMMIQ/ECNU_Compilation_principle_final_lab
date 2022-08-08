#import "../AST/IfStmt.h"
#import "../AST/Program.h"

auto IfStmt::code_gen() -> llvm::Value * {
  llvm::Value *cond = bool_expr->code_gen();
  if (!cond) {
    return nullptr;
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
  auto *then_value = then_stmt->code_gen();

  Program::builder->CreateBr(merge_block);
  then_block = Program::builder->GetInsertBlock();

  func->getBasicBlockList().push_back(else_block);
  Program::builder->SetInsertPoint(else_block);
  auto *else_value = else_stmt->code_gen();

  Program::builder->CreateBr(merge_block);
  else_block = Program::builder->GetInsertBlock();

  func->getBasicBlockList().push_back(merge_block);
  Program::builder->SetInsertPoint(merge_block);
  llvm::PHINode *phi =
      Program::builder->CreatePHI(llvm::Type::getInt32Ty(*Program::context), 2);

  phi->addIncoming(then_value, then_block);
  phi->addIncoming(else_value, else_block);
  return phi;
}
