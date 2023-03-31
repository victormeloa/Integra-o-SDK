#include "catch.hpp"
#include "medidor_de_energia/medidor_de_energia.h"

TEST_CASE("test medidor de energia apolo")
{
    auto test_01 = MedidorDeEnergia("APOLO", "6031", 1, MeterLine::APOLO);

    REQUIRE(test_01.get_model() == "6031");
};

TEST_CASE("test medidor de energia_apolo_01")
{
    auto test_01 = MedidorDeEnergia("APOLO", "6031", 1, MeterLine::APOLO);
    REQUIRE(test_01.get_line() == "APOLO");
};

TEST_CASE("test medidor de energia_apolo_02")
{
    auto test_01 = MedidorDeEnergia("APOLO", "6031", 1, MeterLine::APOLO);
    REQUIRE(test_01.get_meter_line() == MeterLine::APOLO);
};
TEST_CASE("test medidor de energia_apolo_03")
{
    auto test_01 = MedidorDeEnergia("APOLO", "6031", 1, MeterLine::APOLO);
    REQUIRE(test_01.get_id() ==1);
};


TEST_CASE("test medidor de energia cronos")
{
    auto test_02 = MedidorDeEnergia("CRONOS", "6001-A", 2, MeterLine::CRONOS);

    REQUIRE(test_02.get_model() == "6001-A");
};

TEST_CASE("test medidor de energia_cronos_01")
{
    auto test_02 = MedidorDeEnergia("CRONOS", "6031", 2, MeterLine::CRONOS);
    REQUIRE(test_02.get_line() == "CRONOS");
};

TEST_CASE("test medidor de energia_cronos_02")
{
    auto test_02 = MedidorDeEnergia("CRONOS", "6031", 2, MeterLine::CRONOS);
    REQUIRE(test_02.get_meter_line() == MeterLine::CRONOS);
};
TEST_CASE("test medidor de energia_cronos_03")
{
    auto test_02 = MedidorDeEnergia("APOLO", "6031", 2, MeterLine::CRONOS);
    REQUIRE(test_02.get_id() ==2);
};

TEST_CASE ("test medidor_de_energia_ares")
{
    auto test_03 = MedidorDeEnergia("ARES", "7021", 9, MeterLine::ARES);
    REQUIRE(test_03.get_model() == "7021" );

};

TEST_CASE ("test medidor_de_eenergia_ares_1")
{
    auto test_03 = MedidorDeEnergia("ARES", "7021", 9, MeterLine::ARES);
    REQUIRE(test_03.get_line()== "ARES");
};

TEST_CASE ("test medidor_de_eenergia_ares_2")
{
    auto test_03 = MedidorDeEnergia("ARES", "7021", 9, MeterLine::ARES);
    REQUIRE(test_03.get_id() == 9);
};

TEST_CASE ("test medidor_de_eenergia_ares_3")
{
    auto test_03 = MedidorDeEnergia("ARES", "7021", 9, MeterLine::ARES);
    REQUIRE(test_03.get_meter_line() == MeterLine::ARES);
};


TEST_CASE("test medidor de energia zeus")
{
    auto test_04 = MedidorDeEnergia("ZEUS", "8021", 15, MeterLine::ZEUS);

    REQUIRE(test_04.get_model() == "8021");
};

TEST_CASE("test medidor de energia_zeus_01")
{
    auto test_04 = MedidorDeEnergia("ZEUS", "8021", 15, MeterLine::ZEUS);
    REQUIRE(test_04.get_line() == "ZEUS");
};

TEST_CASE("test medidor de energia_zeus_02")
{
    auto test_04 = MedidorDeEnergia("ZEUS ", "8021", 15, MeterLine::ZEUS);
    REQUIRE(test_04.get_meter_line() == MeterLine::ZEUS);
};
TEST_CASE("test medidor de energia_zeus_03")
{
    auto test_04 = MedidorDeEnergia("ZEUS", "8021", 15, MeterLine::ZEUS);
    REQUIRE(test_04.get_id() ==15);
};


