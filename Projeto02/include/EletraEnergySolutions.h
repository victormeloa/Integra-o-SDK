#pragma once

#include "medidor_de_energia/medidor_de_energia.h"
#include <vector>

class EletraEnergySolutions
{
public:
    EletraEnergySolutions();
    void adicionar_medidor(MedidorDeEnergia meter);
    auto get_lista_de_medidores() -> std::vector<MedidorDeEnergia> &;
    auto get_lista_de_medidores_por_linha(const MeterLine &line) ->std::vector<MedidorDeEnergia>;

private:
    std::vector<MedidorDeEnergia> lista_de_medidores;
};