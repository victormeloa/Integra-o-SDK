#include "medidor_de_energia/ares.h"
#include "catch.hpp"


TEST_CASE("teste construtor ares")
{
 Ares Ares( "9031",  100);
        REQUIRE(Ares.get_line()=="ARES");
        REQUIRE (Ares.get_model() =="9031");
        REQUIRE(Ares.get_id() == 100);
        REQUIRE(Ares.get_meter_line() == MeterLine::ARES );   
}


