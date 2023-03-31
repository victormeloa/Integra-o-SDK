#include "medidor_de_energia/cronos.h"

const std::string Cronos::CRONOS_LINE = "CRONOS";

Cronos::Cronos (std::string modelo, int id)
    :MedidorDeEnergia(CRONOS_LINE, modelo, id, MeterLine::CRONOS)
{
}