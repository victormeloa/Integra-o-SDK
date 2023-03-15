#pragma once
#include "medidor_de_energia.h"

class Zeus : public MedidorDeEnergia
{
private:
    static const std::string ZEUS_LINE;
public:
    Zeus(std::string modelo, int id);
 
};
