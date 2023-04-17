#pragma once

#include "grpcpp/impl/codegen/server_context.h"
#include "grpcpp/impl/codegen/sync_stream.h"
#include "grpcpp/impl/codegen/call_op_set.h"
#include "projeto02.pb.h"
#include "projeto02.grpc.pb.h"
#include "EletraEnergySolutions.h"
#include "projeto02_1.grpc.pb.h"
#include "projeto02_1.pb.h"

namespace vma
{
    class Projeto02Service final : public Projeto02::Service
    {
    public:
        grpc::Status GetAllMetersLines(grpc::ServerContext *context, const EmptyRequest *request, GetMeterLineReply *reply) override;
        grpc::Status GetAllMetersEnergy(grpc::ServerContext *contex, const EmptyRequest *request, GetMedidorReply *reply) override;
        grpc::Status getMeters_for_MeterLine(grpc::ServerContext *context, const MeterLineRequest *request, GetMedidorReply *reply) override;
        grpc::Status get_lines_by_meter_list(grpc::ServerContext *context, const EmptyRequest *request, GetMeterLineReply *reply) override;
        grpc::Status AddMeterline(grpc::ServerContext *context, const AddMeterlineRequest *request, GetMedidorReply *reply) override;
        grpc::Status RemoveMeterLine(grpc::ServerContext *context, const RemoveMeterLineRequest *request, GetMedidorReply *reply) override;

        EletraEnergySolutions ees;
    };
}
