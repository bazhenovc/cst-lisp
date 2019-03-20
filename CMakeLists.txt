cmake_minimum_required(VERSION 2.8)

project(cst-lisp-compiler)

set (CMAKE_CXX_STANDARD 17)

add_subdirectory(${PROJECT_SOURCE_DIR}/external/antlr-runtime)

add_executable(${PROJECT_NAME}
    src/main.cc
    src/ast.hh
    src/ast.cc
    src/lisp.g
    tests/basic-test.lisp

    src/generated/lispBaseVisitor.cpp
    src/generated/lispBaseVisitor.h
    src/generated/lispLexer.cpp
    src/generated/lispLexer.h
    src/generated/lispVisitor.cpp
    src/generated/lispVisitor.h
    src/generated/lispParser.cpp
    src/generated/lispParser.h)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/external/include/
    ${PROJECT_SOURCE_DIR}/external/include/antlr)
target_link_directories(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Release>:${PROJECT_SOURCE_DIR}/external/lib/release>
    $<$<CONFIG:Debug>:${PROJECT_SOURCE_DIR}/external/lib/debug>)
target_link_libraries(${PROJECT_NAME}
    LLVMCore LLVMSupport LLVMCodeGen LLVMBinaryFormat LLVMBitReader LLVMBitWriter LLVMMC LLVMMCParser
    LLVMObject LLVMAnalysis LLVMProfileData
    antlr4_static)
