#include "models/Incidente.hpp"
#include <iostream>

std::string tipoIncidenteParaString(TipoIncidente tipo)
{
    switch (tipo)
    {
    case TipoIncidente::CONFLITO_HORARIO:
        return "Conflito de Horario";
    case TipoIncidente::TREM_LOTADO:
        return "Trem Lotado";
    case TipoIncidente::ESTACAO_CHEIA:
        return "Estacao Cheia";
    case TipoIncidente::CANCELAMENTO:
        return "Cancelamento de Viagem";
    case TipoIncidente::ALTERACAO_ROTA:
        return "Alteracao de Rota";
    case TipoIncidente::INCIDENTE:
        return "Incidente Geral";
    default:
        return "Desconhecido";
    }
}

Incidente::Incidente(int cod,
                     TipoIncidente t,
                     std::string desc,
                     int codViagem,
                     std::string d,
                     std::string h)
    : codigo(cod),
      tipo(t),
      descricao(desc),
      codigoViagem(codViagem),
      data(d),
      horario(h) {}

void Incidente::exibir() const
{
    std::cout << "[INCIDENTE #" << codigo << "] Tipo: " << tipoIncidenteParaString(tipo)
              << " | Viagem #" << codigoViagem
              << " | Data: " << data << " " << horario
              << " | Descricao: " << descricao << std::endl;
}