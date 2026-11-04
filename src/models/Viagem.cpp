#include "models/Viagem.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

std::string statusViagemParaString(StatusViagem status)
{
    switch (status)
    {
    case StatusViagem::PROGRAMADA:
        return "Programada";
    case StatusViagem::EM_EMBARQUE:
        return "Em Embarque";
    case StatusViagem::EM_TRANSITO:
        return "Em Transito";
    case StatusViagem::CONCLUIDA:
        return "Concluida";
    case StatusViagem::CANCELADA:
        return "Cancelada";
    default:
        return "Desconhecido";
    }
}

int horarioParaMinutos(const std::string &horario)
{
    if (horario.length() < 5)
        return 0;
    int horas = std::stoi(horario.substr(0, 2));
    int minutos = std::stoi(horario.substr(3, 2));
    return horas * 60 + minutos;
}

std::string minutosParaHorario(int minutos)
{
    int horas = (minutos / 60) % 24;
    int mins = minutos % 60;
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << horas << ":" << std::setw(2) << std::setfill('0')
        << mins;
    return oss.str();
}

Viagem::Viagem(int cod, int codTrem, int codOrigem, int codDestino, int hPartida, int hChegada,
               int qtdPass, std::string r, StatusViagem st)
    : codigo(cod), codigoTrem(codTrem), codigoOrigem(codOrigem), codigoDestino(codDestino),
      horarioPartida(hPartida), horarioChegadaPrevista(hChegada), quantidadePassageiros(qtdPass),
      rota(r), status(st)
{
}

void Viagem::exibir() const
{
    std::cout << "[VIAGEM #" << codigo << "] Trem #" << codigoTrem << " | Origem #" << codigoOrigem
              << " -> Destino #" << codigoDestino
              << " | Partida: " << minutosParaHorario(horarioPartida)
              << " | Chegada: " << minutosParaHorario(horarioChegadaPrevista)
              << " | Pass.: " << quantidadePassageiros
              << " | Status: " << statusViagemParaString(status) << " | Rota: " << rota
              << std::endl;
}