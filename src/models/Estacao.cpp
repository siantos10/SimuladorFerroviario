#include "models/Estacao.hpp"
#include <iostream>

Estacao::Estacao(int cod, std::string n, std::string loc, int cap, int ocup)
    : codigo(cod), nome(n), localizacao(loc), capacidade(cap), ocupacaoAtual(ocup) {}

void Estacao::exibir() const {
    std::cout << "[ESTACAO #" << codigo << "] "
              << nome << " (" << localizacao << ") | "
              << "Ocupacao: " << ocupacaoAtual << "/" << capacidade << " trens"
              << std::endl;
}

bool Estacao::estaLotada() const {
    return ocupacaoAtual >= capacidade;
}