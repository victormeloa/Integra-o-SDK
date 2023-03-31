#pragma once

#include "console.h"
#include "utility.h"
#include "EletraEnergySolutions.h"

class Application
{
public:
    Application();
    void add_meter();
    void add_multiples_meters(MeterLine type);
    void mostrar_lista_de_medidores();
    void delete_meter();
    void run_app();
    void clear();
    void switch_adicionar_medidor();
    
private:
    Console my_menu;
    EletraEnergySolutions ees;
};

