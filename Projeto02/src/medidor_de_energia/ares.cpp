#include "medidor_de_energia/ares.h"

const std::string Ares::ARES_LINE = "ARES";

Ares::Ares (std::string modelo, int id)
    :MedidorDeEnergia(ARES_LINE, modelo, id, MeterLine::ARES)
{
}