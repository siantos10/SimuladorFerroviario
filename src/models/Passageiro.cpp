#include "models/Passageiro.hpp"
#include <iostream>

Passageiro::Passageiro(int cod, std::string n) : codigo(cod), nome(n) {}

void Passageiro::exibir() const
{
    std::cout << "[PASSAGEIRO #" << codigo << "] " << nome << std::endl;
}