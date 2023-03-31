#include "fabrica_de_medidor.h"
#include "medidor_de_energia/apolo.h"
#include "medidor_de_energia/ares.h"
#include "medidor_de_energia/cronos.h"
#include "medidor_de_energia/zeus.h"

auto create_meter(MeterLine meter_line, std::string model, int id) ->std::unique_ptr<MedidorDeEnergia>
{
    switch (meter_line)
    {
    case MeterLine::APOLO:
        return std::make_unique<Apolo>(model,id);
    case MeterLine::ARES:
        return std::make_unique<Ares>(model,id);
    case MeterLine::CRONOS:
        return std::make_unique<Cronos>(model,id);
    case MeterLine::ZEUS:
        return std::make_unique<Zeus>(model,id);
    }
    throw std::exception("\n Escolha inválida\n");
}
