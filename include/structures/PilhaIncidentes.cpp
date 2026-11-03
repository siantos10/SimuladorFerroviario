#include "structures/PilhaIncidentes.hpp"
#include <iostream>
#include <stdexcept>

NoPilhaIncidente::NoPilhaIncidente(const Incidente& inc)
    : incidente(inc), proximo(nullptr) {}

PilhaIncidentes::PilhaIncidentes()
    : topo(nullptr), quantidade(0) {}

PilhaIncidentes::~PilhaIncidentes() {
    limpar();
}

void PilhaIncidentes::push(const Incidente& inc) {
    NoPilhaIncidente* novo = new NoPilhaIncidente(inc);
    novo->proximo = topo;
    topo = novo;
    quantidade++;
}

Incidente PilhaIncidentes::pop() {
    if (vazia()) {
        throw std::runtime_error(" [ERRO] Tentativa de pop em Pilha de Incidentes vazia!");
    }

    NoPilhaIncidente* temp = topo;
    Incidente incRemovido = temp->incidente;

    topo = topo->proximo;
    delete temp;
    quantidade--;

    return incRemovido;
}

Incidente PilhaIncidentes::top() const {
    if (vazia()) {
        throw std::runtime_error(" [ERRO] Tentativa de consultar top em Pilha de Incidentes vazia!");
    }
    return topo->incidente;
}

bool PilhaIncidentes::vazia() const {
    return topo == nullptr;
}

int PilhaIncidentes::tamanho() const {
    return quantidade;
}

void PilhaIncidentes::exibir() const {
    if (vazia()) {
        std::cout << "   [Pilha de Incidentes Vazia]" << std::endl;
        return;
    }

    NoPilhaIncidente* atual = topo;
    int nivel = quantidade;
    while (atual != nullptr) {
        std::cout << "   [Topo " << nivel << "] ";
        atual->incidente.exibir();
        atual = atual->proximo;
        nivel--;
    }
}

void PilhaIncidentes::limpar() {
    while (!vazia()) {
        pop();
    }
}