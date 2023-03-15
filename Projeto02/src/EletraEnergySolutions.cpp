#include "EletraEnergySolutions.h"
#include "medidor_de_energia/ares.h"
#include "medidor_de_energia/zeus.h"
#include "medidor_de_energia/apolo.h"
#include "medidor_de_energia/cronos.h"
#include <string>
#include <iostream>


EletraEnergySolutions::EletraEnergySolutions()
{
  lista_de_medidores =
  {
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
      Zeus("8023", 17),
    }
  };
}

void EletraEnergySolutions::listar_medidores_de_energia()
{
    for(const auto &medidor : lista_de_medidores)
    {
        medidor.mostrar_informacoes_do_medidor();
    }
}

auto EletraEnergySolutions::get_lista_de_medidores() -> std::vector<MedidorDeEnergia>&
{
    return lista_de_medidores;
}

void EletraEnergySolutions::add_meter(MeterLine line, std::string model, int id)
{
    switch (line)
    {
    case MeterLine::APOLO:
        lista_de_medidores.push_back(Apolo(model,id));
        return;
    case MeterLine::CRONOS:
        lista_de_medidores.push_back(Cronos(model,id));
        return;
    case MeterLine::ARES:
        lista_de_medidores.push_back(Ares(model,id));
        return;
    case MeterLine::ZEUS:
        lista_de_medidores.push_back(Zeus(model,id));
        return;
    }
}

void EletraEnergySolutions::list_meters_by_line(const MeterLine &line)
{
    for (const auto &medidor : lista_de_medidores)
    {
        if (medidor.get_meter_line() == line)
        {
            std::cout<<medidor.get_id()<< "  ---------- " <<medidor.mostrar_informacoes_do_medidor()<<std::endl;
        }
           
    }
}

