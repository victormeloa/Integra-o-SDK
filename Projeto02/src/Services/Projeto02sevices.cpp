#include "Services/Projeto02services.h"
#include "Application.h"
#include "fabrica_de_medidor.h"
#include "Services/Projeto02Utilityservices.h"

namespace vma
{
    grpc::Status Projeto02Service::GetAllMetersEnergy(grpc::ServerContext *context, const EmptyRequest *request, GetMedidorReply *reply)
    {
        auto lista_de_medidores = ees.get_lista_de_medidores();
        UtilityServices::print_list(lista_de_medidores, reply);

        return grpc::Status::OK;
    }
    grpc::Status Projeto02Service::GetAllMetersLines(grpc::ServerContext *context, const EmptyRequest *request, GetMeterLineReply *reply)
    {
        reply->add_line(MeterlineProto::APOLO);
        reply->add_line(MeterlineProto::CRONOS);
        reply->add_line(MeterlineProto::ARES);
        reply->add_line(MeterlineProto::ZEUS);

        return grpc::Status::OK;
    }

    grpc::Status Projeto02Service::AddMeterline(grpc::ServerContext *context, const AddMeterlineRequest *request, GetMedidorReply *reply)

    {
        auto line = request->medidor();

        for (auto it = line.begin(); it != line.end(); it++)
        {
            auto medidor = create_meter(UtilityServices::converter_meterLine_proto_for_meter_line(it->line()), it->model(), it->id());
            ees.adicionar_medidor(*medidor);
        }

        auto lista_de_medidores = ees.get_lista_de_medidores();
        UtilityServices::print_list(lista_de_medidores, reply);
        return grpc::Status::OK;
    }

    grpc::Status Projeto02Service::RemoveMeterLine(grpc::ServerContext *context, const RemoveMeterLineRequest *request, GetMedidorReply *reply)
    {
        auto id = request->id();
        for (auto it = id.begin(); it != id.end(); it++)
        {
            ees.delete_meters_for_id(*it);
        }

        auto lista_de_medidores = ees.get_lista_de_medidores();
        UtilityServices::print_list(lista_de_medidores, reply);

        return grpc::Status::OK;
    }

    grpc::Status Projeto02Service::getMeters_for_MeterLine(grpc::ServerContext *context, const MeterLineRequest *request, GetMedidorReply *reply)
    {
        switch (request->meter_line())
        {
        case MeterlineProto::APOLO:
            UtilityServices::print_list(ees.get_lista_de_medidores_por_linha(MeterLine::APOLO), reply);
            break;
        case MeterlineProto::ARES:
            UtilityServices::print_list(ees.get_lista_de_medidores_por_linha(MeterLine::ARES), reply);
            break;
        case MeterlineProto::CRONOS:
            UtilityServices::print_list(ees.get_lista_de_medidores_por_linha(MeterLine::CRONOS), reply);
            break;
        case MeterlineProto::ZEUS:
            UtilityServices::print_list(ees.get_lista_de_medidores_por_linha(MeterLine::ZEUS), reply);
            break;
        case MeterlineProto::UNKNOWN:
            UtilityServices::print_list(ees.get_lista_de_medidores_por_linha(MeterLine::UNKNOWN), reply);
            break;
        }

        return grpc::Status::OK;
    }


    grpc::Status Projeto02Service::get_lines_by_meter_list(grpc::ServerContext *context, const EmptyRequest *request, GetMeterLineReply *reply)
    {

        auto list = ees.get_lines_by_meter_line();
             
        for (const auto &line : list)
        {
            reply->add_line(UtilityServices::converter_for_meterline(line));
        }

        return grpc::Status::OK;
    }


}



