// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Forma Normal de Chomsky
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 26/10/2023
// Archivo main.cc: programa principal

#include <iostream>
#include <string>

#include "cfg.h"
#include "alphabet.h"

int main(int argc, char* argv[]) {
  //Usage(argc, argv);
  std::string terminals = "ab";
  std::string non_terminals = "SABC";
  Alphabet terminals_set(terminals);
  Alphabet non_terminals_set(non_terminals);
  char axiom = 'S';
  Cfg grammar(terminals_set, non_terminals_set, axiom);
  grammar.AddProduction('S', "ABb");
  grammar.AddProduction('S', "ABC");
  grammar.AddProduction('A', "aB");
  grammar.AddProduction('A', "&");
  grammar.AddProduction('B', "bB");
  grammar.AddProduction('B', "&");
  grammar.AddProduction('C', "abC");
  grammar.AddProduction('C', "AB");
  std::cout << grammar << std::endl;
  grammar.DeleteAndSubstituteEmptyProductions();
  std::cout << grammar << std::endl;
  return 0;
}
