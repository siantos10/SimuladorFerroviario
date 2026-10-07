#pragma once

#include <string>

// Enum class para controle seguro dos estados do Trem [REQUISITO OFICIAL]
enum class StatusTrem {
    DISPONIVEL,
    EM_EMBARQUE,
    EM_TRANSITO,
    AGUARDANDO_ESTACAO,
    MANUTENCAO
};

// Funcao auxiliar para conversao de enum para texto legivel
std::string statusTremParaString(StatusTrem status);

// Struct de Dominio representando o Trem [REQUISITO OFICIAL]
struct Trem {
    int codigo;
    int capacidade;
    double velocidade;
    std::string tipo;
    StatusTrem status;

    // Construtor padrao
    Trem(int cod = 0, int cap = 0, double vel = 0.0, 
         std::string t = "", StatusTrem st = StatusTrem::DISPONIVEL);

    // Exibe os dados do trem no console
    void exibir() const;
};