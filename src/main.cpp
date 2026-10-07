#include <iostream>
#include "models/Trem.hpp"
#include "models/Estacao.hpp"

int main() {
    std::cout << "====================================================" << std::endl;
    std::cout << "  TESTE INICIAL - ALUNO 1 (SEMANA 1)                " << std::endl;
    std::cout << "====================================================" << std::endl;

    // Teste da entidade Trem
    Trem trem1(101, 200, 120.5, "Passageiros", StatusTrem::DISPONIVEL);
    
    // Teste da entidade Estacao
    Estacao estacao1(1, "Estacao Central", "Recife", 4, 1);

    std::cout << "\n--- Entidade Trem ---" << std::endl;
    trem1.exibir();

    std::cout << "\n--- Entidade Estacao ---" << std::endl;
    estacao1.exibir();

    std::cout << "\n====================================================" << std::endl;
    return 0;
}