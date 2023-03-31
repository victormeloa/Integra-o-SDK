#include "medidor_de_energia/medidor_de_energia.h"

MedidorDeEnergia::MedidorDeEnergia(std::string line, std::string model, int id, MeterLine meter_line)
    : line(line), model(model), id(id), meter_line(meter_line)
{
}

MedidorDeEnergia::MedidorDeEnergia()
{

}

std::string MedidorDeEnergia::mostrar_informacoes_do_medidor() const 
{
    return line + "  --------- " + model;
}

auto MedidorDeEnergia::get_line() const -> std::string
{
    return line;
}

auto MedidorDeEnergia::get_model() const -> std::string
{
    return model;
}

auto MedidorDeEnergia::get_id() const -> int
{
    return id;
}

bool MedidorDeEnergia::operator==(const MedidorDeEnergia &medidor) const
{
    return (medidor.get_meter_line()==this->meter_line) &&(medidor.get_line() == this->line) && (medidor.get_model() == this->model) && (medidor.get_id()== this ->id);
}

auto MedidorDeEnergia::get_meter_line() const -> MeterLine
{
    return meter_line;
}


