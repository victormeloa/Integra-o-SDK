#include <vector>
#include <string>


class WaterMeter

{
public:
void display_line_meter_water();
void display_line_zlink();


private:

const std::vector<std::string> water_meter = {"ZLINK"};
const std::vector<std::string> zlink = {"Ultrassônicos"};

};