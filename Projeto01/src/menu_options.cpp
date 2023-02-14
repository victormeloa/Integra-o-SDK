#include <iostream>
#include "menu_options.h"


void MenuOptions::display_options_menu()
{
    std::cout << "Selecione o tipo de Medidores" << std::endl;
};

void MenuOptions::display_typers_meter()
{
    std::cout <<"1.Medidores de energia\n2.Medidores de água\n3.Religadores\n5.Todos os Produtos\n4.Todos os Produtos\n5.Sair da Aplicação"<< std::endl;
};



