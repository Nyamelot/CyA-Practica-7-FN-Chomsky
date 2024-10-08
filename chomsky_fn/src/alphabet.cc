// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Forma Normal de Chomsky
// Autor: José Ángel Portillo García
// Correo: alu0101568232@ull.edu.es
// Fecha: 26/10/2023

#include <iostream>

#include "alphabet.h"

std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet) {
   for (const auto& symbol : alphabet.GetAlphabet()) {
     out << symbol << " ";
   }
  return out;
}