#pragma once

#include <string>

// Struct de Dominio representando o Passageiro [REQUISITO OFICIAL]
struct Passageiro
{
    int codigo;
    std::string nome;

    // Construtor padrao
    Passageiro(int cod = 0, std::string n = "");

    // Exibe os dados do passageiro no terminal
    void exibir() const;
};