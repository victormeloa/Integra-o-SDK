#include <iostream>
#include "menu_options.h"
#include "meter_energy.h"
#include "meter_water.h"
#include "religadores.h"
#include "controle.h"
#include "textos.h"


EnergyMeter my_meter_energy;
WaterMeter my_meter_water;
Religators my_religators;
MenuOptions my_menu_options;
Textos my_selector_model_meter_energy;
Textos my_selector_model_meter_water;
Textos my_selector_model_religators;


int selecao=0;




void Controle::controle()
{
    int selecao=0;
   my_menu_options.display_options_menu();
   my_menu_options.display_typers_meter();
   std:: cin >> selecao;


        while (1)
        {
            switch (selecao)
           {
           

            case 1:
            system("cls");
               
               my_meter_energy.display_line_meter_energy();
               my_selector_model_meter_energy.display_selector_model_meter_energy();
               my_meter_energy.display_line_apolo();
               my_meter_energy.display_line_cronos();
               my_meter_energy.display_line_ares();
               my_meter_energy.display_line_zeus();
               std::cin >> selecao;

            case 2: 
            system ("cls");
            
               my_meter_water.display_line_meter_water();
               my_selector_model_meter_energy.display_selector_model_meter_water();
               my_meter_water.display_line_zlink();
               std::cin >> selecao;

            
            case 3:
            system ("cls");
               my_selector_model_religators.display_selector_model_religators();
               my_religators.display_religators();
               std::cin >> selecao;

            
            case 4:
            system("cls");
               my_menu_options.display_options_menu();
               my_menu_options.display_typers_meter();
               my_religators.display_religators();
               my_meter_energy.display_line_meter_energy();
               my_meter_energy.display_line_apolo();
               my_meter_energy.display_line_cronos();
               my_meter_energy.display_line_ares();
               my_meter_energy.display_line_zeus();
               my_meter_water.display_line_meter_water();
               my_meter_water.display_line_zlink();
               my_religators.display_religators();
               std::cin >> selecao;



            }
    if (selecao==5)
    {
        break;
    }

}
}



   