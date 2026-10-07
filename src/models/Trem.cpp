#include "models/Trem.hpp"
#include <iostream>

std::string statusTremParaString(StatusTrem status) {
    switch (status) {
        case StatusTrem::DISPONIVEL:         return "Disponivel";
        case StatusTrem::EM_EMBARQUE:        return "Em Embarque";
        case StatusTrem::EM_TRANSITO:        return "Em Transito";
        case StatusTrem::AGUARDANDO_ESTACAO: return "Aguardando Estacao";
        case StatusTrem::MANUTENCAO:         return "Em Manutencao";
        default:                             return "Desconhecido";
    }
}

Trem::Trem(int cod, int cap, double vel, std::string t, StatusTrem st)
    : codigo(cod), capacidade(cap), velocidade(vel), tipo(t), status(st) {}

void Trem::exibir() const {
    std::cout << "[TREM #" << codigo << "] "
              << "Tipo: " << tipo << " | "
              << "Capacidade: " << capacidade << " pass. | "
              << "Velocidade: " << velocidade << " km/h | "
              << "Status: " << statusTremParaString(status)
              << std::endl;
}