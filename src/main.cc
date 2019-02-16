/** MIT License

    Copyright (c) 2019 Kyrylo Bazhenov

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#pragma warning(push)
#pragma warning(disable:4146)
#pragma warning(disable:4141)
#pragma warning(disable:4244)
#pragma warning(disable:4267)
#pragma warning(disable:4291)
#pragma warning(disable:4624)
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS  1

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/BasicBlock.h>

#include <llvm/ADT/StringRef.h>

#include <llvm/Bitcode/BitcodeReader.h>
#include <llvm/Bitcode/BitcodeWriter.h>

#undef _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(pop)

#include "ast.hh"
#include "parser.hh"

#include <fstream>
#include <iostream>

llvm::StringRef ToLLVM(std::string_view sv)
{
    return llvm::StringRef(sv.data(), sv.size());
}

void ParseAndGenerate(Parser& parser, std::string_view inFile, std::string_view outFile)
{
    std::unique_ptr<llvm::LLVMContext>  LLVMContext;
    std::unique_ptr<llvm::Module>       Module;
    std::unique_ptr<llvm::IRBuilder<>>  Builder;

    LLVMContext = std::make_unique<llvm::LLVMContext>();
    Module = std::make_unique<llvm::Module>(ToLLVM(inFile), *LLVMContext.get());
    Builder = std::make_unique<llvm::IRBuilder<>>(*LLVMContext.get());

    AST::GeneratedScope rootScope;
    rootScope.Types.insert(std::make_pair("void", llvm::Type::getVoidTy(*LLVMContext.get())));
    rootScope.Types.insert(std::make_pair("bool", llvm::Type::getInt1Ty(*LLVMContext.get())));
    rootScope.Types.insert(std::make_pair("f16", llvm::Type::getHalfTy(*LLVMContext.get())));
    rootScope.Types.insert(std::make_pair("f32", llvm::Type::getFloatTy(*LLVMContext.get())));
    rootScope.Types.insert(std::make_pair("f64", llvm::Type::getDoubleTy(*LLVMContext.get())));
    rootScope.Types.insert(std::make_pair("f128", llvm::Type::getFP128Ty(*LLVMContext.get())));
    rootScope.Types.insert(std::make_pair("i8", llvm::Type::getInt8Ty(*LLVMContext.get())));
    rootScope.Types.insert(std::make_pair("i16", llvm::Type::getInt16Ty(*LLVMContext.get())));
    rootScope.Types.insert(std::make_pair("i32", llvm::Type::getInt32Ty(*LLVMContext.get())));
    rootScope.Types.insert(std::make_pair("i64", llvm::Type::getInt64Ty(*LLVMContext.get())));
    rootScope.Types.insert(std::make_pair("i128", llvm::Type::getInt128Ty(*LLVMContext.get())));
    rootScope.Types.insert(std::make_pair("u8", llvm::Type::getInt8Ty(*LLVMContext.get())));
    rootScope.Types.insert(std::make_pair("u16", llvm::Type::getInt16Ty(*LLVMContext.get())));
    rootScope.Types.insert(std::make_pair("u32", llvm::Type::getInt32Ty(*LLVMContext.get())));
    rootScope.Types.insert(std::make_pair("u64", llvm::Type::getInt64Ty(*LLVMContext.get())));
    rootScope.Types.insert(std::make_pair("u128", llvm::Type::getInt128Ty(*LLVMContext.get())));
    rootScope.RootBlock = llvm::BasicBlock::Create(*LLVMContext.get(), "__module_main");

    auto rootForm = std::make_unique<AST::FormExpression>(parser.GetParseContext(parser.PeekToken()),
                                                          std::vector<AST::BaseExpressionPtr>(),
                                                          AST::FormExpression::FormScope());
    while (Token token = parser.NextToken()) {
        rootForm->Body.emplace_back(parser.ParseToplevelForm(token, rootForm->Scope));
    }

    // Debug pring AST
    rootForm->DebugPrint(0);

    // Generate code
    AST::CodeGenContext context = {
        rootScope,
        Builder.get(),
        Module.get(),
        LLVMContext.get(),
    };
    rootForm->Generate(context);

    // Debug print bitcode
    Module->print(llvm::errs(), nullptr);
    llvm::errs().flush();

    // Write bitcode to file
    std::error_code errorCode;
    llvm::raw_fd_ostream outStream(ToLLVM(outFile), errorCode, llvm::sys::fs::F_None);
    if (!errorCode) {
        llvm::WriteBitcodeToFile(*Module.get(), outStream);
        outStream.flush();
    } else {
        std::cerr << "Failed to write bitcode:" << errorCode << std::endl;
    }

    rootForm.reset();
    Builder.reset();
    Module.reset();
    LLVMContext.reset();
}

int main(int argc, char** argv)
{
    if (argc < 3) {
        std::cerr << "Usage: chisel <input file> <output file>" << std::endl;
        return -1;
    }

    std::ifstream inStream(argv[1], std::ios::in);
    if (!inStream.good()) {
        std::cerr << "Failed to open input file:" << argv[1] << std::endl;
        return -1;
    }

    if (inStream.good()) {
        inStream.seekg(0, inStream.end);
        size_t fileSize = size_t(inStream.tellg());
        inStream.seekg(0, inStream.beg);

        std::string data;
        data.resize(fileSize);
        inStream.read(&data[0], fileSize);

        Lexer lexer(std::string_view(data.c_str(), fileSize));

        Parser parser{ lexer };
        ParseAndGenerate(parser, argv[1], argv[2]);
    }

    return 0;
}
