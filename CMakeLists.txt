cmake_minimum_required(VERSION 3.18)
project(ECNU_Compilation_principle_final_lab)

set(CMAKE_CXX_STANDARD 20)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(llvm_libs
        Analysis
        Core
        ExecutionEngine
        InstCombine
        Object
        OrcJIT
        RuntimeDyld
        ScalarOpts
        Support
        native)

add_executable(ECNU_Compilation_principle_final_lab src/main.cpp src/Lexer/Lexer.cpp src/Lexer/Lexer.h src/AST/Program.h src/AST/Expr.h src/AST/IntNumExpr.h src/AST/RealNumExpr.h src/AST/IdExpr.h src/AST/BinaryExpr.h src/AST/BoolBinaryExpr.h src/AST/ArithBinaryExpr.h src/Parser/BoolBinaryExpr.cpp src/AST/Stmt.h src/AST/IfStmt.h src/AST/AssgStmt.h src/AST/CompoundStmt.h src/AST/Decl.h src/AST/IntDecl.h src/AST/RealDecl.h)

target_link_libraries(ECNU_Compilation_principle_final_lab ${llvm_libs})
