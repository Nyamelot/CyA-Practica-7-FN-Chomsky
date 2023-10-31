// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Forma Normal de Chomsky
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 26/10/2023

#include <string>
#include <iomanip>
#include <iostream>
#include <set>

#include "cfg.h"

const std::string kTitle = "P07-Chomsky-Normal-Form";
const std::string kHelpText =
"  \n\033[1m>> Example:\033[0m"\
"    ./a.out input.gra\n"\
  
"  \033[1m>> Parameters:\033[0m\n"\
"     - \033[1minput.gra:\033[0m is the cfg to be transformed\n"\

"  \033[1m>> Output:\033[0m\n"\
"    The program will output the transformed cfg"\
" in a new .gra file.\n";


/**
 * @brief Enable the use of Usage to read input by command line
 * 
 * @param argc 
 * @param argv 
 */
void Usage(int argc, char* argv[]) {
  const std::string kHelp = "--help";
  if (argc == 1) {
    std::cerr << argv[0] << std::endl << kTitle << std::endl;
    std::cerr << "How to use: " << argv[0]
              << " input.gra"
              << std::endl;
    std::cerr << "Try " << argv[0] << " --help for more information."
              << std::endl;
    exit(EXIT_FAILURE);
  }
  if (argv[1] == kHelp) {
    std::cout << kTitle << std::endl;
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
  if ((argc > 2) || ((argc < 2))) {
    std::cerr << argv[0] << std::endl << kTitle << std::endl;
    std::cerr << "How to use: " << argv[0]
              << " input.gra"
              << std::endl;
    std::cerr << "Try " << argv[0] << " --help for more information."
              << std::endl;
    exit(EXIT_FAILURE);
  }
}

std::ostream& operator<<(std::ostream& out, Cfg grammar) {
  out << grammar.GetTerminals().GetAlphabet().size() << std::endl;
  for (const auto& terminal : grammar.GetTerminals().GetAlphabet()) {
    out << terminal << std::endl;
  }
  out << grammar.GetNonTerminals().GetAlphabet().size() << std::endl;
  for (const auto& non_terminal : grammar.GetNonTerminals().GetAlphabet()) {
    out << non_terminal << std::endl;
  }
  out << grammar.GetProductions().size() << std::endl;
  for (const auto& production : grammar.GetProductions()) {
    out << production.first << " " << production.second << std::endl;
  }
  return out;
}

void Cfg::AddProduction(char non_terminal, std::string expression) {
  if (!non_terminals_.GetAlphabet().count(non_terminal)) {
    std::cerr << "The non terminal does not match then list of non terminals" << std::endl;
    exit(EXIT_FAILURE);
  }
  for (const auto& symbol : expression) {
    if (!terminals_.GetAlphabet().count(symbol) && 
    !non_terminals_.GetAlphabet().count(symbol)) {
      std::cerr << "The expression does not match the list of terminals or the list of terminals" 
      << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  std::pair<char, std::string> production = {non_terminal, expression};
  productions_.emplace(production);
}

void Cfg::NullifyCounter() {
  std::set<char> null_non_terminals;
  for (const auto& production : productions_) {
    for(const auto& symbol : production.second) {
      if (symbol == '&') {
        null_non_terminals.emplace(production.first);
      }
    }
  }
}
