#pragma once

#include "models/Trem.hpp"

// No interno da Arvore Binaria de Busca para Trens [DECISÃO TÉCNICA]
struct NoABBTrem {
    Trem* trem;
    NoABBTrem* esquerda;
    NoABBTrem* direita;

    NoABBTrem(Trem* t);
};

// Interface da Arvore Binaria de Busca de Trens (Implementacao Manual sem STL) [REQUISITO OFICIAL]
class ABBTrem {
private:
    NoABBTrem* raiz;
    int quantidade;

    // Metodos auxiliares recursivos
    NoABBTrem* inserirRecursivo(NoABBTrem* no, Trem* t);
    Trem* buscarRecursivo(NoABBTrem* no, int codigo) const;
    NoABBTrem* removerRecursivo(NoABBTrem* no, int codigo);
    NoABBTrem* encontrarMenor(NoABBTrem* no) const;
    void percursoEmOrdemRecursivo(NoABBTrem* no) const;
    void destruirRecursivo(NoABBTrem* no);

public:
    ABBTrem();
    ~ABBTrem();

    // Bloqueio de copia rasa
    ABBTrem(const ABBTrem&) = delete;
    ABBTrem& operator=(const ABBTrem&) = delete;

    // Operacoes da ABB
    void inserir(Trem* t);               // Insere ponteiro de trem por codigo
    Trem* buscar(int codigo) const;      // Busca por codigo e retorna Trem* (ou nullptr)
    void remover(int codigo);            // Remove no da arvore mantendo propriedade de ABB
    void percursoEmOrdem() const;        // Exibe os trens em ordem crescente de codigo
    bool vazia() const;                  // Verifica se a arvore esta vazia
    int tamanho() const;                 // Retorna o numero de nos
    void limpar();                       // Desaloca todos os nos da arvore
};