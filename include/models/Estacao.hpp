#pragma once

#include <string>

// Struct de Dominio representando a Estacao [REQUISITO OFICIAL]
struct Estacao {
    int codigo;
    std::string nome;
    std::string localizacao;
    int capacidade;      // Capacidade maxima de trens simultaneos
    int ocupacaoAtual;   // Trens atualmente na estacao

    // Construtor padrao
    Estacao(int cod = 0, std::string n = "", std::string loc = "", 
            int cap = 0, int ocup = 0);

    // Exibe os dados da estacao no console
    void exibir() const;

    // Verifica se a estacao atingiu o limite maximo de trens
    bool estaLotada() const;
};