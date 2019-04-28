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

#include "ast.hh"
#include "module_builder.hh"

#pragma warning(push)
#pragma warning(disable:4146)
#pragma warning(disable:4141)
#pragma warning(disable:4244)
#pragma warning(disable:4267)
#pragma warning(disable:4291)
#pragma warning(disable:4624)
#pragma warning(disable:4996)
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS  1

#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FormattedStream.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/InitLLVM.h"

#undef _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(pop)

static llvm::cl::opt<std::string> SourceFile(llvm::cl::Positional,
                                             llvm::cl::desc("Input file name"),
                                             llvm::cl::init("-"));

static llvm::cl::opt<std::string> BinaryIROutput("ir-binary",
                                                 llvm::cl::desc("Binary IR output file"),
                                                 llvm::cl::init(""));
static llvm::cl::opt<std::string> PlainTextIROutput("ir-plaintext",
                                                    llvm::cl::desc("Human readable IR output file (can use stdout)"),
                                                    llvm::cl::init(""));

int main(int argc, char** argv)
{
    llvm::InitLLVM LLVMInitializer(argc, argv);
    (void)LLVMInitializer;

    llvm::cl::ParseCommandLineOptions(argc, argv);

    std::ifstream inStream(SourceFile, std::ios::in);
    if (!inStream.good()) {
        std::cerr << "Failed to open input file:" << SourceFile << std::endl;
        return -1;
    }

    if (inStream.good()) {
        antlr4::ANTLRInputStream inputStream(inStream);
        lispLexer lexer(&inputStream);
        antlr4::CommonTokenStream tokenStream(&lexer);
        lispParser parser(&tokenStream);

        lispParser::ProgramContext* programContext = parser.program();

        llvm::LLVMContext llvmContext;

        ModuleBuilder builder;
        ModuleBuilder::CodeGenResult result = builder.ParseAndGenerate(SourceFile, &llvmContext, programContext);
        (void)result;

        std::error_code errorCode;

        // plaintext output
        if (PlainTextIROutput != "") {
            if (PlainTextIROutput == "stdout") {
                result.Module->print(llvm::errs(), nullptr);
                llvm::errs().flush();
            } else {
                llvm::raw_fd_ostream outStream(PlainTextIROutput, errorCode,
                                               llvm::sys::fs::CD_CreateAlways,
                                               llvm::sys::fs::FA_Write,
                                               llvm::sys::fs::F_Text);
                if (!errorCode) {
                    result.Module->print(outStream, nullptr);
                    outStream.flush();
                } else {
                    std::cerr << "Failed to write plaintext IR: " << errorCode << std::endl;
                    return 1;
                }
            }
        }

        // binary output
        if (BinaryIROutput != "") {
            llvm::raw_fd_ostream outStream(BinaryIROutput, errorCode, llvm::sys::fs::F_None);
            if (!errorCode) {
                llvm::WriteBitcodeToFile(*result.Module.get(), outStream);
                outStream.flush();
            } else {
                std::cerr << "Failed to write binary IR: " << errorCode << std::endl;
                return 1;
            }
        }
    }

    return 0;
}
