#include "services/AcervoCentral.hpp"
#include <iostream>

int main()
{
    std::cout << "====================================================" << std::endl;
    std::cout << "  TESTE INTEGRADO - EDSON (SEMANA 2)               " << std::endl;
    std::cout << "====================================================" << std::endl;

    AcervoCentral acervo;

    std::cout << "\n1. Cadastrando Trens no Acervo Central..." << std::endl;
    acervo.cadastrarTrem(101, 200, 120.0, "Passageiros");
    acervo.cadastrarTrem(102, 300, 90.0, "Carga");

    std::cout << " Tentando cadastrar trem duplicado (#101):" << std::endl;
    acervo.cadastrarTrem(101, 150, 100.0, "Passageiros");

    std::cout << "\n2. Cadastrando Estacoes no Acervo Central..." << std::endl;
    acervo.cadastrarEstacao(1, "Estacao Central", "Recife", 5);
    acervo.cadastrarEstacao(2, "Estacao Agreste", "Caruaru", 3);

    std::cout << "\n3. Buscando entidades pelo ID..." << std::endl;
    Trem *t = acervo.buscarTrem(101);
    if (t != nullptr)
    {
        std::cout << " [SUCESSO] Trem localizado no acervo: ";
        t->exibir();
    }

    Estacao *e = acervo.buscarEstacao(1);
    if (e != nullptr)
    {
        std::cout << " [SUCESSO] Estacao localizada no acervo: ";
        e->exibir();
    }

    std::cout << "\n4. Finalizando programa (destrutor ~AcervoCentral desalocara a memoria "
                 "automaticamente)..."
              << std::endl;
    std::cout << "====================================================" << std::endl;
    return 0;
}