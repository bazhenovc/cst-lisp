cmake_minimum_required(VERSION 2.8)

project(cst-lisp-compiler)

set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_CXX_STANDARD 17)

set (LLVM_LIB_DIR_DEBUG CACHE PATH "")
set (LLVM_LIB_DIR_RELEASE CACHE PATH "")

add_subdirectory(${PROJECT_SOURCE_DIR}/external/antlr-runtime)

add_executable(${PROJECT_NAME}
    src/main.cc
    src/ast.hh
    src/ast.cc
    src/module_builder.hh
    src/module_builder.cc
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
    $<$<CONFIG:Release>:${LLVM_LIB_DIR_RELEASE}>
    $<$<CONFIG:Debug>:${LLVM_LIB_DIR_DEBUG}>)

target_link_libraries(${PROJECT_NAME}
    antlr4_static
    #LLVMAArch64AsmParser
    #LLVMAArch64AsmPrinter
    #LLVMAArch64CodeGen
    #LLVMAArch64Desc
    #LLVMAArch64Disassembler
    #LLVMAArch64Info
    #LLVMAArch64Utils

    #LLVMAMDGPUAsmParser
    #LLVMAMDGPUAsmPrinter
    #LLVMAMDGPUCodeGen
    #LLVMAMDGPUDesc
    #LLVMAMDGPUDisassembler
    #LLVMAMDGPUInfo
    #LLVMAMDGPUUtils

    #LLVMARMAsmParser
    #LLVMARMAsmPrinter
    #LLVMARMCodeGen
    #LLVMARMDesc
    #LLVMARMDisassembler
    #LLVMARMInfo
    #LLVMARMUtils

    #LLVMBPFAsmParser
    #LLVMBPFAsmPrinter
    #LLVMBPFCodeGen
    #LLVMBPFDesc
    #LLVMBPFDisassembler
    #LLVMBPFInfo

    #LLVMHexagonAsmParser
    #LLVMHexagonCodeGen
    #LLVMHexagonDesc
    #LLVMHexagonDisassembler
    #LLVMHexagonInfo

    #LLVMLanaiAsmParser
    #LLVMLanaiAsmPrinter
    #LLVMLanaiCodeGen
    #LLVMLanaiDesc
    #LLVMLanaiDisassembler
    #LLVMLanaiInfo

    #LLVMMipsAsmParser
    #LLVMMipsAsmPrinter
    #LLVMMipsCodeGen
    #LLVMMipsDesc
    #LLVMMipsDisassembler
    #LLVMMipsInfo

    #LLVMMSP430AsmPrinter
    #LLVMMSP430CodeGen
    #LLVMMSP430Desc
    #LLVMMSP430Info

    #LLVMNVPTXAsmPrinter
    #LLVMNVPTXCodeGen
    #LLVMNVPTXDesc
    #LLVMNVPTXInfo

    #LLVMPowerPCAsmParser
    #LLVMPowerPCAsmPrinter
    #LLVMPowerPCCodeGen
    #LLVMPowerPCDesc
    #LLVMPowerPCDisassembler
    #LLVMPowerPCInfo

    #LLVMSparcAsmParser
    #LLVMSparcAsmPrinter
    #LLVMSparcCodeGen
    #LLVMSparcDesc
    #LLVMSparcDisassembler
    #LLVMSparcInfo

    #LLVMSystemZAsmParser
    #LLVMSystemZAsmPrinter
    #LLVMSystemZCodeGen
    #LLVMSystemZDesc
    #LLVMSystemZDisassembler
    #LLVMSystemZInfo

    #LLVMXCoreAsmPrinter
    #LLVMXCoreCodeGen
    #LLVMXCoreDesc
    #LLVMXCoreDisassembler
    #LLVMXCoreInfo

    #LLVMX86AsmParser
    #LLVMX86AsmPrinter
    #LLVMX86CodeGen
    #LLVMX86Desc
    #LLVMX86Disassembler
    #LLVMX86Info
    #LLVMX86Utils

    LLVMCore
    LLVMSupport
    LLVMCodeGen
    LLVMBinaryFormat
    LLVMBitReader
    LLVMBitWriter
    LLVMMC
    LLVMMCParser
    LLVMObject
    LLVMAnalysis
    LLVMProfileData

    #LLVMAggressiveInstCombine
    #LLVMAsmParser
    #LLVMAsmPrinter
    #LLVMCoroutines
    #LLVMCoverage
    #LLVMDebugInfoCodeView
    #LLVMDebugInfoDWARF
    #LLVMDebugInfoMSF
    #LLVMDebugInfoPDB
    #LLVMDemangle
    #LLVMDlltoolDriver
    #LLVMExecutionEngine
    #LLVMFuzzMutate
    #LLVMGlobalISel
    #LLVMInstCombine
    #LLVMInstrumentation
    #LLVMInterpreter
    #LLVMipo
    #LLVMIRReader
    #LLVMLibDriver
    #LLVMLineEditor
    #LLVMLinker
    #LLVMLTO
    #LLVMMCDisassembler
    #LLVMMCJIT
    #LLVMMIRParser
    #LLVMObjCARCOpts
    #LLVMObjectYAML
    #LLVMOption
    #LLVMOrcJIT
    #LLVMPasses
    #LLVMRuntimeDyld
    #LLVMScalarOpts
    #LLVMSelectionDAG
    #LLVMSymbolize
    #LLVMTableGen
    #LLVMTarget
    #LLVMTestingSupport
    #LLVMTransformUtils
    #LLVMVectorize
    #LLVMWindowsManifest
    #LLVMXRay
)
