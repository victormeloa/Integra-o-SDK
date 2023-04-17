#include "catch.hpp"
#include "Services/Projeto02Utilityservices.h"

TEST_CASE("testing converter_for_meterline")
{
   UtilityServices test_switch_convert;

   REQUIRE(test_switch_convert.converter_for_meterline(MeterLine::APOLO) == vma::MeterlineProto::APOLO);
   REQUIRE(test_switch_convert.converter_for_meterline(MeterLine::ARES) == vma::MeterlineProto::ARES);
   REQUIRE(test_switch_convert.converter_for_meterline(MeterLine::CRONOS) == vma::MeterlineProto::CRONOS);
   REQUIRE(test_switch_convert.converter_for_meterline(MeterLine::ZEUS) == vma::MeterlineProto::ZEUS);
   REQUIRE(test_switch_convert.converter_for_meterline(MeterLine::UNKNOWN) == vma::MeterlineProto::UNKNOWN);
}

TEST_CASE("testing converter_meterline_proto_for_meterline")
{
   UtilityServices test_switch_convert_meterline_proto_for_meterline;
   REQUIRE(test_switch_convert_meterline_proto_for_meterline.converter_meterLine_proto_for_meter_line(vma::MeterlineProto::APOLO) == MeterLine::APOLO);
   REQUIRE(test_switch_convert_meterline_proto_for_meterline.converter_meterLine_proto_for_meter_line(vma::MeterlineProto::ARES) == MeterLine::ARES);
   REQUIRE(test_switch_convert_meterline_proto_for_meterline.converter_meterLine_proto_for_meter_line(vma::MeterlineProto::CRONOS) == MeterLine::CRONOS);
   REQUIRE(test_switch_convert_meterline_proto_for_meterline.converter_meterLine_proto_for_meter_line(vma::MeterlineProto::ZEUS) == MeterLine::ZEUS);
   REQUIRE(test_switch_convert_meterline_proto_for_meterline.converter_meterLine_proto_for_meter_line(vma::MeterlineProto::UNKNOWN) == MeterLine::UNKNOWN);
}

TEST_CASE("testing print_list")
{
   UtilityServices utils;

   std::vector<MedidorDeEnergia> lista =
       {
           MedidorDeEnergia("LINHA1", "MODELO1", 1, MeterLine::APOLO),
           MedidorDeEnergia("LINHA3", "MODELO2", 2, MeterLine::CRONOS),
           MedidorDeEnergia("LINHA2", "MODELO3", 3, MeterLine::ARES),
           MedidorDeEnergia("LINHA4", "MODELO4", 4, MeterLine::ZEUS)

       };

   vma::GetMedidorReply reply;

   utils.print_list(lista, &reply);

   REQUIRE(reply.medidor().size() == 4);

   REQUIRE(reply.medidor().at(0).model() == "MODELO1");
   REQUIRE(reply.medidor().at(0).line() == vma::MeterlineProto::APOLO);
   REQUIRE(reply.medidor().at(0).id() == 1);

   REQUIRE(reply.medidor().at(1).model() == "MODELO2");
   REQUIRE(reply.medidor().at(1).line() == vma::MeterlineProto::CRONOS);
   REQUIRE(reply.medidor().at(1).id() == 2);

   REQUIRE(reply.medidor().at(2).model() == "MODELO3");
   REQUIRE(reply.medidor().at(2).line() == vma::MeterlineProto::ARES);
   REQUIRE(reply.medidor().at(2).id() == 3);

   REQUIRE(reply.medidor().at(3).model() == "MODELO4");
   REQUIRE(reply.medidor().at(3).line() == vma::MeterlineProto::ZEUS);
   REQUIRE(reply.medidor().at(3).id() == 4);
}
