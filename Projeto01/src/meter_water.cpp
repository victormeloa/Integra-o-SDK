#include <iostream>
#include"meter_water.h"


void WaterMeter::display_line_meter_water()
{
    for (int i=0; i<water_meter.size(); i++)
    {
        std::cout << water_meter[i] << std::endl;
    }
}
    void WaterMeter::display_line_zlink()
{
    for (int i=0; i<zlink.size(); i++)
    {
        std::cout << zlink[i] << std::endl;
    }

 }




