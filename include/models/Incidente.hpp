#pragma once

#include <string>

// Enum class para tipificar os incidentes operacionais [REQUISITO OFICIAL]
enum class TipoIncidente
{
    CONFLITO_HORARIO,
    TREM_LOTADO,
    ESTACAO_CHEIA,
    CANCELAMENTO,
    ALTERACAO_ROTA,
    INCIDENTE
};

// Funcao auxiliar para converter o enum TipoIncidente em texto legivel
std::string tipoIncidenteParaString(TipoIncidente tipo);

// Struct de Dominio representando o Incidente / Ocorrencia [REQUISITO OFICIAL]
struct Incidente
{
    int codigo;
    TipoIncidente tipo;
    std::string descricao;
    int codigoViagem;
    std::string data;
    std::string horario;

    // Construtor padrao
    Incidente(int cod = 0, TipoIncidente t = TipoIncidente::INCIDENTE,
              std::string desc = "", int codViagem = 0,
              std::string d = "", std::string h = "");

    // Exibe os dados do incidente no terminal
    void exibir() const;
};