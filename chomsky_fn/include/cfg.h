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

 private:
  Alphabet terminals_;
  std::set<std::string> non_terminals_;
  std::string axiom_;
};

#endif