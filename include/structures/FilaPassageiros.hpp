#pragma once

#include "models/Passageiro.hpp"

// No interno da Fila de Passageiros [DECISÃO TÉCNICA]
struct NoFilaPassageiro
{
    Passageiro passageiro;
    NoFilaPassageiro *proximo;

    NoFilaPassageiro(const Passageiro &p);
};

// Interface da Fila de Passageiros (Implementacao Manual FIFO sem STL) [REQUISITO OFICIAL]
class FilaPassageiros
{
private:
    NoFilaPassageiro *inicio;
    NoFilaPassageiro *fim;
    int quantidade;

public:
    FilaPassageiros();
    ~FilaPassageiros();

    // Bloqueio de copia rasa para evitar double free
    FilaPassageiros(const FilaPassageiros &) = delete;
    FilaPassageiros &operator=(const FilaPassageiros &) = delete;

    // Operacoes fundamentais da Fila FIFO
    void enqueue(const Passageiro &p); // Insere no fim
    Passageiro dequeue();              // Remove e retorna do inicio
    Passageiro front() const;          // Consulta inicio sem remover
    bool vazia() const;                // Verifica se esta vazia
    int tamanho() const;               // Retorna numero de elementos
    void exibir() const;               // Imprime a fila no terminal
    void limpar();                     // Desaloca todos os nos
};