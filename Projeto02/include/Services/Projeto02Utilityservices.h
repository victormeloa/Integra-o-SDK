#include "projeto02.grpc.pb.h"
#include "projeto02_1.grpc.pb.h"
#include "EletraEnergySolutions.h"

class UtilityServices
{
public:
        static auto converter_for_meterline(const MeterLine &line) -> vma::MeterlineProto;
        static auto converter_meterLine_proto_for_meter_line(const vma::MeterlineProto &meterline_proto) -> MeterLine;
        static void print_list(const std::vector<MedidorDeEnergia> &lista_de_medidores, vma::GetMedidorReply *reply);
};


