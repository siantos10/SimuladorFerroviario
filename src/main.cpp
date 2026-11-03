#include <iostream>
#include "models/Trem.hpp"
#include "models/Estacao.hpp"
#include "models/Passageiro.hpp"
#include "models/Viagem.hpp"
#include "models/Incidente.hpp"

int main()
{
    std::cout << "====================================================" << std::endl;
    std::cout << "  TESTE INICIAL - ALUNO 3 (SEMANA 1)                " << std::endl;
    std::cout << "====================================================" << std::endl;

    // Teste da entidade Incidente
    Incidente inc1(1, TipoIncidente::CANCELAMENTO, "Manutencao nao programada na via", 1001, "06/10/2026", "08:15");

    std::cout << "\n--- Entidade Incidente ---" << std::endl;
    inc1.exibir();

    std::cout << "\n====================================================" << std::endl;
    return 0;
}