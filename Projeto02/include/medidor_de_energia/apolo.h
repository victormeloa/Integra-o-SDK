#pragma once
#include "medidor_de_energia/medidor_de_energia.h"
#include <string>

class Apolo : public MedidorDeEnergia
{
private:
    static const std::string APOLO_LINE;
public:
    Apolo(std::string modelo, int id);
};