#include "structures/ListaDuplaHistorico.hpp"
#include <iostream>

NoListaViagem::NoListaViagem(const Viagem& v)
    : viagem(v), anterior(nullptr), proximo(nullptr) {}

ListaDuplaHistorico::ListaDuplaHistorico()
    : cabeca(nullptr), cauda(nullptr), quantidade(0) {}

ListaDuplaHistorico::~ListaDuplaHistorico() {
    limpar();
}

void ListaDuplaHistorico::inserirFim(const Viagem& v) {
    NoListaViagem* novo = new NoListaViagem(v);

    if (vazia()) {
        cabeca = novo;
        cauda = novo;
    } else {
        cauda->proximo = novo;
        novo->anterior = cauda;
        cauda = novo;
    }
    quantidade++;
}

void ListaDuplaHistorico::listarInicioFim() const {
    if (vazia()) {
        std::cout << "   [Historico de Viagens Vazio]" << std::endl;
        return;
    }

    NoListaViagem* atual = cabeca;
    int pos = 1;
    while (atual != nullptr) {
        std::cout << "   " << pos << ". ";
        atual->viagem.exibir();
        atual = atual->proximo;
        pos++;
    }
}

void ListaDuplaHistorico::listarFimInicio() const {
    if (vazia()) {
        std::cout << "   [Historico de Viagens Vazio]" << std::endl;
        return;
    }

    NoListaViagem* atual = cauda;
    int pos = quantidade;
    while (atual != nullptr) {
        std::cout << "   " << pos << ". ";
        atual->viagem.exibir();
        atual = atual->anterior;
        pos--;
    }
}

bool ListaDuplaHistorico::vazia() const {
    return cabeca == nullptr;
}

int ListaDuplaHistorico::tamanho() const {
    return quantidade;
}

void ListaDuplaHistorico::limpar() {
    NoListaViagem* atual = cabeca;
    while (atual != nullptr) {
        NoListaViagem* proximoNo = atual->proximo;
        delete atual;
        atual = proximoNo;
    }
    cabeca = nullptr;
    cauda = nullptr;
    quantidade = 0;
}