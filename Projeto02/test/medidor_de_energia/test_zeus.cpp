#include "medidor_de_energia/zeus.h"
#include "catch.hpp"


TEST_CASE("teste construtor zeus")
{
    Zeus Zeus( "9020",  100);
        REQUIRE(Zeus.get_line()=="ZEUS");
        REQUIRE (Zeus.get_model() =="9020");
        REQUIRE(Zeus.get_id() == 100);
        REQUIRE(Zeus.get_meter_line() == MeterLine::ZEUS);

}

