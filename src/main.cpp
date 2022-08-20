#include "AST/Program.h"
#include "Lexer/PreLexer.h"

#include <gflags/gflags.h>

#include <fstream>

DEFINE_string(c, "", "source file");
DEFINE_string(o, "", "output file");
DEFINE_bool(O, false, "optimize");
DEFINE_bool(C, false, "output bitcode IR");
DEFINE_bool(S, false, "output text IR");
DEFINE_bool(s, false, "output assembly");

int main(int argc, char **argv) {
  google::SetUsageMessage("Usage: ./compiler [options]\n"
                          "Generates binary executables by default\n"
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

  if (FLAGS_C + FLAGS_S + FLAGS_s > 1) {
    std::cerr << "only one of -C, -S, -s can be specified" << std::endl;
    return 1;
  }

  if (FLAGS_O) {
    auto tmp = "opt -O1 -S " + FLAGS_o + " -o " + FLAGS_o;
    system(tmp.data());
  }

  if (FLAGS_C) {
    auto tmp = "llvm-as " + FLAGS_o + " -o " + FLAGS_o;
    system(tmp.data());
  }

  if (FLAGS_s) {
    auto tmp = "llc " + FLAGS_o + " -o " + FLAGS_o;
    system(tmp.data());
  }

  if (!FLAGS_S && !FLAGS_C && !FLAGS_s) {
    auto tmp = "llvm-link " + FLAGS_o + " -o " + FLAGS_o;
    system(tmp.data());
    tmp = "chmod +x " + FLAGS_o;
    system(tmp.data());
  }

  return 0;
}
