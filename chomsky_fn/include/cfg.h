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

#include "alphabet.h"

void Usage(int argc, char* argv[]);

class CFG {
 public:
  // Constructor
  CFG(Alphabet alphabet) : terminals_(alphabet) {}

  // Getters
  inline const Alphabet GetTerminals() const { return terminals_; }
  inline const std::set<char> GetNonTerminals() const { return non_terminals_; }
  inline const char GetAxiom() const { return axiom_; }

  // Methods

 private:
  Alphabet terminals_;
  std::set<char> non_terminals_;
  char axiom_;
};

#endif