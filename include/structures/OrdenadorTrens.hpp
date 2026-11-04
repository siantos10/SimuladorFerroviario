#pragma once

#include <vector>
#include "models/Viagem.hpp"
#include "models/Trem.hpp"

// Interface utilitaria para ordenacao manual via QuickSort [REQUISITO OFICIAL]
class OrdenadorTrens {
private:
    // Funcoes auxiliares de particionamento e ordenacao recursiva para Viagens
    static int particionarPorHorario(std::vector<Viagem*>& viagens, int baixo, int alto);
    static void quickSortViagensRec(std::vector<Viagem*>& viagens, int baixo, int alto);

    // Funcoes auxiliares de particionamento e ordenacao recursiva para Trens
    static int particionarPorCapacidade(std::vector<Trem*>& trens, int baixo, int alto);
    static void quickSortTrensCapacidadeRec(std::vector<Trem*>& trens, int baixo, int alto);

    static int particionarPorVelocidade(std::vector<Trem*>& trens, int baixo, int alto);
    static void quickSortTrensVelocidadeRec(std::vector<Trem*>& trens, int baixo, int alto);

    // Troca manual de ponteiros sem utilizar std::swap
    template<typename T>
    static void trocar(T*& a, T*& b) {
        T* temp = a;
        a = b;
        b = temp;
    }

public:
    // Ordena vetor de ponteiros de Viagem por horario de partida (crescente)
    static void ordenarViagensPorHorario(std::vector<Viagem*>& viagens);

    // Ordena vetor de ponteiros de Trem por capacidade (decrescente)
    static void ordenarTrensPorCapacidade(std::vector<Trem*>& trens);

    // Ordena vetor de ponteiros de Trem por velocidade (decrescente)
    static void ordenarTrensPorVelocidade(std::vector<Trem*>& trens);
};