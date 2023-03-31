#include "catch.hpp"
#include "EletraEnergySolutions.h"
#include "medidor_de_energia/medidor_de_energia.h"
#include "medidor_de_energia/zeus.h"
#include "fabrica_de_medidor.h"
#include "medidor_de_energia/apolo.h"
#include "medidor_de_energia/zeus.h"

TEST_CASE("adicionar medidor")
{
  EletraEnergySolutions add;

  auto medidor = MedidorDeEnergia("ZEUS", "9050", 30, MeterLine::ZEUS);
  add.adicionar_medidor(medidor);
  auto meter = add.get_lista_de_medidores().back();
  REQUIRE(meter == medidor);
};

TEST_CASE("lista de medidores")
{
  EletraEnergySolutions ees;

  REQUIRE(ees.get_lista_de_medidores().size() == 17);
};

TEST_CASE("lista medidores por linha apolo")
{
  EletraEnergySolutions ees;
  std::vector<MedidorDeEnergia> line_01 = {Apolo("6031",1)};
  REQUIRE(ees.get_lista_de_medidores_por_linha(MeterLine::APOLO) == line_01 );
};

TEST_CASE("lista medidores por linha zeus")
{
  EletraEnergySolutions ees;
  std::vector<MedidorDeEnergia> line_01 = {Zeus("8021",15), Zeus("8031",16), Zeus("8023",17)};
  REQUIRE(ees.get_lista_de_medidores_por_linha(MeterLine::ZEUS) == line_01 );
};


//TEST_CASE ("test listar medidores por linha")
//{
//  EletraEnergySolutions ees;
//  std::vector<MedidorDeEnergia> line_01 = {Zeus("8021",15)};
//  REQUIRE(ees.get_lista_de_medidores_por_linha(MeterLine::ZEUS) == line_01 );
//};