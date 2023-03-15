#pragma once

#include "Medidor.h"
#include <string>

enum class MeterLine
{
    APOLO,
    CRONOS,
    ARES,
    ZEUS
};

class MedidorDeEnergia
{
public:
    MedidorDeEnergia(std::string line, std::string model, int id, MeterLine meter_line = MeterLine::APOLO);

    bool operator==(const MedidorDeEnergia &medidor) const;
    virtual std::string mostrar_informacoes_do_medidor() const;
    auto get_line() const -> std::string;
    auto get_model() const -> std::string;
    auto get_id() const -> int;
    auto get_meter_line() const -> MeterLine;
private:
    std::string line;
    int id;
    std::string model;
    MeterLine meter_line;
};