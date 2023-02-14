#include <vector>
#include <string>


class EnergyMeter

{
public:
void display_line_meter_energy();
void display_line_apolo();
void display_line_cronos();
void display_line_ares();
void display_line_zeus();

private:

const std::vector<std::string> energy_meter = {"APOLO", "CRONOS", "ARES", "ZEUS"};
const std::vector<std::string> apolo = {"APOLO 6031"};
const std::vector<std::string> cronos = {"CRONOS 6001-A", "CRONOS 6021-A", "CRONOS 6021L", "CRONOS 6003", "CRONOS 7023", "CRONOS 7023L", "CRONOS 7023 2,5"};
const std::vector<std::string> ares = {"ARES 7021", "ARES 7031", "ARES 7023", "ARES 8023", "ARES 8023 15", "ARES 8023 200"};
const std::vector<std::string> zeus = {"ZEUS 8021", "ZEUS 8031", "ZEUS 8023"};

};