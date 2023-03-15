#include "medidor_de_energia/cronos.h"
#include "catch.hpp"


TEST_CASE("teste construtor cronos")
{
   Cronos Cronos( "9020",  100);
        REQUIRE(Cronos.get_line()=="CRONOS");
        REQUIRE (Cronos.get_model() =="9051");
        REQUIRE(Cronos.get_id() == 100);
        REQUIRE(Cronos.get_meter_line() == MeterLine::CRONOS );

}

