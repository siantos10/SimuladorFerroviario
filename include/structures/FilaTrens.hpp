#pragma once

#include "models/Trem.hpp"

// No interno da Fila de Trens (ponteiro nao-proprietario para Trem) [DECISÃO TÉCNICA]
struct NoFilaTrem
{
    Trem *trem;
    NoFilaTrem *proximo;

    NoFilaTrem(Trem *t);
};

// Interface da Fila de Trens da Estacao (Implementacao Manual FIFO sem STL) [REQUISITO OFICIAL]
class FilaTrens
{
private:
    NoFilaTrem *inicio;
    NoFilaTrem *fim;
    int quantidade;

public:
    FilaTrens();
    ~FilaTrens();

    // Bloqueio de copia rasa
    FilaTrens(const FilaTrens &) = delete;
    FilaTrens &operator=(const FilaTrens &) = delete;

    // Operacoes fundamentais da Fila FIFO
    void enqueue(Trem *t); // Insere ponteiro no fim
    Trem *dequeue();       // Remove e retorna ponteiro do inicio
    Trem *front() const;   // Consulta ponteiro do inicio
    bool vazia() const;    // Verifica se esta vazia
    int tamanho() const;   // Quantidade de trens na fila
    void exibir() const;   // Exibe a fila
    void limpar();         // Limpa os nos sem deletar os objetos Trem
};