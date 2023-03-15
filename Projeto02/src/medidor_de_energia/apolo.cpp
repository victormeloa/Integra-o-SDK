#include "medidor_de_energia/apolo.h"

const std::string Apolo::APOLO_LINE = "APOLO";

Apolo::Apolo (std::string modelo, int id)
    :MedidorDeEnergia(APOLO_LINE, modelo, id, MeterLine::APOLO)
{
}