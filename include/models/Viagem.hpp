#pragma once

#include <string>

// Enum class para controle seguro dos estados da Viagem [REQUISITO OFICIAL]
enum class StatusViagem
{
    PROGRAMADA,
    EM_EMBARQUE,
    EM_TRANSITO,
    CONCLUIDA,
    CANCELADA
};

// Funcao auxiliar para conversao de enum para texto legivel
std::string statusViagemParaString(StatusViagem status);

// Funcoes utilitarias de conversao de horario (HH:MM <-> minutos a partir de 00:00)
int horarioParaMinutos(const std::string &horario);
std::string minutosParaHorario(int minutos);

// Struct de Dominio representando a Viagem [REQUISITO OFICIAL]
struct Viagem
{
    int codigo;
    int codigoTrem;
    int codigoOrigem;
    int codigoDestino;
    int horarioPartida;         // em minutos
    int horarioChegadaPrevista; // em minutos
    int quantidadePassageiros;
    std::string rota;
    StatusViagem status;

    // Construtor padrao
    Viagem(int cod = 0, int codTrem = 0, int codOrigem = 0, int codDestino = 0,
           int hPartida = 0, int hChegada = 0, int qtdPass = 0,
           std::string r = "", StatusViagem st = StatusViagem::PROGRAMADA);

    // Exibe os dados da viagem no terminal
    void exibir() const;
};