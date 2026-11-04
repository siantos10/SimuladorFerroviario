#pragma once

#include "models/Estacao.hpp"
#include "models/Trem.hpp"
#include <string>
#include <vector>

// Classe responsavel pelo gerenciamento central de memoria e acervo de cadastros base
class AcervoCentral
{
  private:
    // Vetores proprietarios de ponteiros (Single Owner Pattern)
    std::vector<Trem *> trens;
    std::vector<Estacao *> estacoes;

  public:
    AcervoCentral();
    ~AcervoCentral();

    // Bloqueio de copia rasa para garantir Single Ownership
    AcervoCentral(const AcervoCentral &) = delete;
    AcervoCentral &operator=(const AcervoCentral &) = delete;

    // Cadastros e Buscas Base [REQUISITO OFICIAL]
    bool cadastrarTrem(int codigo, int capacidade, double velocidade, const std::string &tipo);
    Trem *buscarTrem(int codigo) const;

    bool cadastrarEstacao(int codigo, const std::string &nome, const std::string &localizacao,
                          int capacidade);
    Estacao *buscarEstacao(int codigo) const;

    // Getters dos acervos
    const std::vector<Trem *> &getTrens() const;
    const std::vector<Estacao *> &getEstacoes() const;

    // Limpeza e Desalocacao de Memoria (RAII)
    void limparTudo();
};