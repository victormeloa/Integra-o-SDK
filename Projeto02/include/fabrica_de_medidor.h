#include "medidor_de_energia/medidor_de_energia.h"
#include <memory>

auto create_meter(MeterLine meter_line, std::string model, int id) -> std::unique_ptr<MedidorDeEnergia>;
