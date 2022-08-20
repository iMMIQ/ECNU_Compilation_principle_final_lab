cmake_minimum_required(VERSION 3.18)
project(ECNU_Compilation_principle_final_lab)

set(CMAKE_CXX_STANDARD 20)

find_package(LLVM REQUIRED CONFIG)
find_package(gflags REQUIRED)

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

file(GLOB_RECURSE sources_cpp CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE sources_h CONFIGURE_DEPENDS "src/*.h")
add_executable(compiler ${sources_cpp} ${sources_h})

target_link_libraries(compiler ${llvm_libs} gflags)
