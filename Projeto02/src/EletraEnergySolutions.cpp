#include "EletraEnergySolutions.h"
#include "medidor_de_energia/ares.h"
#include "medidor_de_energia/zeus.h"
#include "medidor_de_energia/apolo.h"
#include "medidor_de_energia/cronos.h"

EletraEnergySolutions::EletraEnergySolutions()
{
    lista_de_medidores =
    {
        Apolo("6031", 1),
        Cronos("6001-A", 2),
        Cronos("6021-A", 3),
        Cronos("6021-L", 4),
        Cronos("6003", 5),
        Cronos("7023", 6),
        Cronos("7023-L", 7),
        Cronos("7023 2,5", 8),
        Ares("7021", 9),
        Ares("7031", 10),
        Ares("7023", 11),
        Ares("8023", 12),
        Ares("8023 15", 13),
        Ares("8023 200", 14),
        Zeus("8021", 15),
        Zeus("8031", 16),
        Zeus("8023", 17)
    };
}

auto EletraEnergySolutions::get_lista_de_medidores() -> std::vector<MedidorDeEnergia> &
{
    return lista_de_medidores;
}

void EletraEnergySolutions::adicionar_medidor(MedidorDeEnergia meter)
{
    lista_de_medidores.push_back(meter);
}

auto EletraEnergySolutions::get_lista_de_medidores_por_linha(const MeterLine &line) -> std::vector<MedidorDeEnergia>
{
    std::vector<MedidorDeEnergia> linhas;

    for (const auto &medidor : lista_de_medidores)
    {
        if (medidor.get_meter_line() == line)
        {
            linhas.push_back(medidor);
        }
    }

    return linhas;
}

void EletraEnergySolutions::delete_meters_for_id(int id)
{
    for (auto it = get_lista_de_medidores().begin(); it !=get_lista_de_medidores().end(); it++)
    {
     if (it->get_id() == id)
        {
          it = get_lista_de_medidores().erase(it);
          break;
        }
    }

}

bool check_if_exist(const std::vector<MeterLine> &lines, const MeterLine &line_compare)
{
    for (const auto &line : lines)
    {
        if (line == line_compare)
            return false;
    }
    return true;
}

auto EletraEnergySolutions::get_lines_by_meter_line() -> std::vector<MeterLine>
{
    std::vector<MeterLine> lines;

    for (const auto &medidor : lista_de_medidores)
    {
       if (check_if_exist(lines, medidor.get_meter_line()))
        {
            lines.emplace_back(medidor.get_meter_line());
        }
    }
    return lines;
}



