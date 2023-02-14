#include <iostream>
#include "meter_energy.h"


 void EnergyMeter::display_line_meter_energy()

 {
    for (int i=0; i<energy_meter.size(); i++)
    {
        std::cout << energy_meter[i] << std::endl;
    }

 }
 

  void EnergyMeter::display_line_apolo()

 {
    for (int i=0; i<apolo.size(); i++)
    {
        std::cout << apolo[i] << std::endl;
    }

 }

  void EnergyMeter::display_line_cronos()

 {
    for (int i=0; i<cronos.size(); i++)
    {
        std::cout << cronos[i] << std::endl;
    }

 }


  void EnergyMeter::display_line_ares()

 {
    for (int i=0; i<ares.size(); i++)
    {
        std::cout << ares[i] << std::endl;
    }

 }

  void EnergyMeter::display_line_zeus()

 {
    for (int i=0; i<zeus.size(); i++)
    {
        std::cout << zeus[i] << std::endl;
    }

 }

