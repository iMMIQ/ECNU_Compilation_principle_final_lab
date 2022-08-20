#include "AST/Program.h"
#include "Lexer/PreLexer.h"
#include <fstream>
#include <gflags/gflags.h>

DEFINE_string(c, "", "source file");
DEFINE_string(o, "", "output file");
// DEFINE_bool(O, false, "optimize");
// DEFINE_bool(C, false, "output bitcode IR");
// DEFINE_bool(S, true, "output text IR");
// DEFINE_bool(s, false, "output assembly");

int main(int argc, char **argv) {
  google::SetUsageMessage("Usage: ./compiler [options]\n"
                          "Default output text IR\n"
                          "Options:\n"
                          "  -c <file>     source file\n"
                          "  -o <file>     output file\n"
                          "  -O            optimize\n"
                          "  -C            output bitcode IR\n"
                          "  -S            output text IR\n"
                          "  -s            output assembly\n");
  google::SetVersionString("v1.0.0");

  google::ParseCommandLineFlags(&argc, &argv, true);
  if (FLAGS_c.empty()) {
    google::ShowUsageWithFlagsRestrict(argv[0], "compiler");
    return 0;
  }

  std::ifstream in(FLAGS_c);
  if (!in.is_open()) {
    std::cerr << "open file " << FLAGS_c << " failed" << std::endl;
    return 1;
  }

  std::string code;
  std::string s;

  while (in >> s) {
    PreLexer::addSpace(s);
    code += s + ' ';
  }

  while (code.find("  ") != std::string::npos) {
    code.replace(code.find("  "), 2, " ");
  }

  std::stringstream ss(code);

  Program::in = &ss;
  Program::parse();
  Program::code_gen();

  std::error_code EC;
  llvm::raw_fd_ostream out(FLAGS_o, EC);

  Program::module->print(out, nullptr);

  return 0;
}
