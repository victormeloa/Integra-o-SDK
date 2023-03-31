#include "medidor_de_energia/apolo.h"
#include "catch.hpp"

TEST_CASE("test construtor apolo")
{
    Apolo Apolo( "9020",  100);

    REQUIRE(Apolo.get_line()=="APOLO");
    REQUIRE(Apolo.get_model() =="9020");
    REQUIRE(Apolo.get_id() == 100);
    REQUIRE(Apolo.get_meter_line() == MeterLine::APOLO );
}

TEST_CASE ("test constutor apolo")
{
    Apolo Apolo( "9011", 150);

    REQUIRE(Apolo.get_line()=="APOLO");
    REQUIRE(Apolo.get_model() == "9011");
    REQUIRE(Apolo.get_id()==150);
    REQUIRE(Apolo.get_meter_line() == MeterLine::APOLO );
}
