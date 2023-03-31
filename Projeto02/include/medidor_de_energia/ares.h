#pragma once
#include "medidor_de_energia/medidor_de_energia.h"
#include <string>

class Ares : public MedidorDeEnergia
{
private:
    static const std::string ARES_LINE;
public:
    Ares(std::string modelo, int id);
};