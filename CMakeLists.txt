cmake_minimum_required(VERSION 3.18)
project(ECNU_Compilation_principle_final_lab)

set(CMAKE_CXX_STANDARD 14)

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

add_executable(ECNU_Compilation_principle_final_lab main.cpp)

target_link_libraries(ECNU_Compilation_principle_final_lab ${llvm_libs})
