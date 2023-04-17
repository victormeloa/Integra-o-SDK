#include "Services/Projeto02Utilityservices.h"

auto UtilityServices::converter_for_meterline(const MeterLine &line) -> vma::MeterlineProto
{
    switch (line)
    {
    case MeterLine::APOLO:
        return vma::MeterlineProto::APOLO;
    case MeterLine::CRONOS:
        return vma::MeterlineProto::CRONOS;
    case MeterLine::ARES:
        return vma::MeterlineProto::ARES;
    case MeterLine::ZEUS:
        return vma::MeterlineProto::ZEUS;
    }
        return vma::MeterlineProto::UNKNOWN;
}

auto UtilityServices::converter_meterLine_proto_for_meter_line(const vma::MeterlineProto &meterline_proto) -> MeterLine
{
    switch (meterline_proto)
    {
    case vma::MeterlineProto::APOLO:
        return MeterLine::APOLO;
    case vma::MeterlineProto::CRONOS:
        return MeterLine::CRONOS;
    case vma::MeterlineProto::ARES:
        return MeterLine::ARES;
    case vma::MeterlineProto::ZEUS:
        return MeterLine::ZEUS;
    }

    return MeterLine::UNKNOWN;
}


void UtilityServices::print_list(const std::vector<MedidorDeEnergia> &lista_de_medidores, vma::GetMedidorReply *reply)
{
    for (int i=0; i < lista_de_medidores.size(); i++)
    {
        auto medidor = lista_de_medidores.at(i);
        auto ptr = reply->add_medidor();
        ptr -> set_id (medidor.get_id());
        ptr -> set_model(medidor.get_model());
        ptr ->set_line(converter_for_meterline(medidor.get_meter_line()));
    }
}  




