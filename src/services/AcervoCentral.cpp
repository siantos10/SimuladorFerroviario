#include "services/AcervoCentral.hpp"
#include <iostream>

AcervoCentral::AcervoCentral() {}

AcervoCentral::~AcervoCentral()
{
    limparTudo();
}

bool AcervoCentral::cadastrarTrem(int codigo, int capacidade, double velocidade,
                                  const std::string &tipo)
{
    // Validacao de Unicidade
    if (buscarTrem(codigo) != nullptr)
    {
        std::cout << " [ERRO] Trem com codigo #" << codigo << " ja cadastrado!" << std::endl;
        return false;
    }

    // Instanciacao dinamica e armazenamento proprietario
    Trem *novoTrem = new Trem(codigo, capacidade, velocidade, tipo, StatusTrem::DISPONIVEL);
    trens.push_back(novoTrem);
    return true;
}

Trem *AcervoCentral::buscarTrem(int codigo) const
{
    for (auto *t : trens)
    {
        if (t->codigo == codigo)
        {
            return t;
        }
    }
    return nullptr;
}

bool AcervoCentral::cadastrarEstacao(int codigo, const std::string &nome,
                                     const std::string &localizacao, int capacidade)
{
    // Validacao de Unicidade
    if (buscarEstacao(codigo) != nullptr)
    {
        std::cout << " [ERRO] Estacao com codigo #" << codigo << " ja cadastrada!" << std::endl;
        return false;
    }

    // Instanciacao dinamica e armazenamento proprietario
    Estacao *novaEstacao = new Estacao(codigo, nome, localizacao, capacidade, 0);
    estacoes.push_back(novaEstacao);
    return true;
}

Estacao *AcervoCentral::buscarEstacao(int codigo) const
{
    for (auto *e : estacoes)
    {
        if (e->codigo == codigo)
        {
            return e;
        }
    }
    return nullptr;
}

const std::vector<Trem *> &AcervoCentral::getTrens() const
{
    return trens;
}

const std::vector<Estacao *> &AcervoCentral::getEstacoes() const
{
    return estacoes;
}

void AcervoCentral::limparTudo()
{
    // Liberacao explicita de cada ponteiro alocado na heap
    for (auto *t : trens)
    {
        delete t;
    }
    trens.clear();

    for (auto *e : estacoes)
    {
        delete e;
    }
    estacoes.clear();
}