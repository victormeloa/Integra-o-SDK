#pragma once

#include "medidor_de_energia.h"
#include "console.h"
#include <vector>

class EletraEnergySolutions
{
public:
    EletraEnergySolutions();
    void listar_medidores_de_energia();
    void add_meter(MeterLine line, std::string model, int id);
    auto get_lista_de_medidores() -> std::vector<MedidorDeEnergia>&;
    void list_meters_by_line(const MeterLine &line);
private:
    std::vector<MedidorDeEnergia> lista_de_medidores;
};