// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Forma Normal de Chomsky
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 26/10/2023

#ifndef ALPHABET_H
#define ALPHABET_H

#include <set>
#include <iostream>
#include <string>

class Alphabet {
 public:
  //Constructor

  
  Alphabet(std::string strings) {
    for (const auto& symbol : strings) {
      if (symbol != ' ' || symbol != '&') {
        alphabet_.emplace(symbol);
      }
    }
  }
  
  //Getter
  inline const std::set<char> GetAlphabet() const { return alphabet_; }

  //Operator Overloading
  friend std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet);

 private:
  std::set<char> alphabet_;
};

#endif
