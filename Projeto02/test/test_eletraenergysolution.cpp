#include "catch.hpp"
#include "EletraEnergySolutions.h"
#include  "medidor_de_energia.h"
#include "medidor_de_energia/zeus.h"

  TEST_CASE("adicionar medidor")
{
        EletraEnergySolutions add;
        add.add_meter(MeterLine::ZEUS, "3030", 90);

        Zeus Zeus("3030", 90);
        auto meter = add.get_lista_de_medidores().end();
        REQUIRE(meter == Zeus("3030",90) );
};