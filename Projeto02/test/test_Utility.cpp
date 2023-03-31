#include "catch.hpp"
#include "Utility.h"

TEST_CASE("teste do switch do seletor 0")
{
    Utility test_switch_seletor;
    auto test_switch_2 = test_switch_seletor.get_seletor(4);
    REQUIRE (test_switch_2 == Seletor::APOLO);
}

TEST_CASE("teste do switch do seletor 1")
{
    Utility test_switch_seletor;
    auto test_switch_2 = test_switch_seletor.get_seletor(3);
    REQUIRE (test_switch_2 == Seletor::CRONOS);
}

TEST_CASE ("teste do switch do selection 1")
{
    Utility test_switch_selec;
    auto test_switch_selec_2 = test_switch_selec.get_seletor_2(5);
    REQUIRE(test_switch_selec_2 == Selection::ADICIONAR_MEDIDOR_DE_ENERGIA);
}

TEST_CASE ("teste do  switch do selection 0")
{
    Utility test_switch_selec;
    auto test_switch_selec_2 = test_switch_selec.get_seletor_2(4);
    REQUIRE(test_switch_selec_2 == Selection::REMOVER_MEDIDOR_DE_ENERGIA);
}



