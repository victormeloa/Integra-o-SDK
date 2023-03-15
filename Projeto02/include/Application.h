#pragma once

#include "console.h"
#include "EletraEnergySolutions.h"
#include "medidor_de_energia.h"
#include <fstream>


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
private:
    Menus my_menu;
    EletraEnergySolutions ees;
    std::string file_path = ".\\meters.txt";

    std::ofstream output_file;
};

