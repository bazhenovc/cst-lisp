cmake_minimum_required(VERSION 2.8)

project(Chisel)

set (CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
    src/main.cc
    src/ast.hh
    src/ast.cc
    src/parser.hh
    src/parser.cc
    tests/basic-test.lisp)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/include)
target_link_directories(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Release>:${PROJECT_SOURCE_DIR}/lib/release>
    $<$<CONFIG:Debug>:${PROJECT_SOURCE_DIR}/lib/debug>)
target_link_libraries(${PROJECT_NAME}
    LLVMCore LLVMSupport LLVMCodeGen LLVMBinaryFormat LLVMBitReader LLVMBitWriter LLVMMC LLVMMCParser
    LLVMObject LLVMAnalysis LLVMProfileData)
