// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Forma Normal de Chomsky
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 26/10/2023

#ifndef CFG_H
#define CFG_H

#include <iostream>
#include <set>
#include <string>
#include <map>

#include "alphabet.h"

void Usage(int argc, char* argv[]);

class Cfg {
 public:
  // Constructor
  Cfg(Alphabet terminals, Alphabet non_terminals, char axiom) : 
  terminals_(terminals), non_terminals_(non_terminals), axiom_(axiom) {}

  // Getters
  inline const Alphabet GetTerminals() const { return terminals_; }
  inline const Alphabet GetNonTerminals() const { return non_terminals_; }
  inline const char GetAxiom() const { return axiom_; }
  inline const std::multimap<char, std::string> GetProductions() const { return productions_; }

  // Methods
  void AddProduction(char non_terminal, std::string expression);
  std::set<char> NullifyCounter();
  void DeleteAndSubstituteEmptyProductions();
  void ChomskyNormalForm();

  // Operator Overloading
  friend std::ostream& operator<<(std::ostream& out, Cfg grammar);

 private:
  Alphabet terminals_;
  Alphabet non_terminals_;
  char axiom_;
  std::multimap<char, std::string> productions_;

};

#endif