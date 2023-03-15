#include "console.h"
#include "medidor_de_energia.h"
#include <iostream>

void Menus::menu_seletor()
{   
    std::cout<<"Qual a linha você deseja inserir um novo modelo?: "<<std::endl;
    std::cout<<"1-APOLO\n2-CRONOS\n3-ARES\n4-ZEUS\n5-voltar para o menu principal"<<std::endl;
}

void Menus::menu_insercao()
{
    std::cout<<"Insira o número do modelo que deseja inserir: "<<std::endl;
}   

void Menus::menu_intro()
{
    std::cout<<"Bem vindo ao portifolio de medidores de energia"<<std::endl;
    std::cout<<"Abaixo vemos os medidores de energia disponíveis"<<std::endl;
}

void Menus::menu_seperador()
{
    std::cout<<"ID ******** LINE *********** MODELO" <<std::endl;
}

void Menus::menu_delete()
{
    std::cout << "Qual o id você gostaria de deletar?" << std::endl;
}

void Menus::menu_delete_2()

{
    std::cout << "Gostaria de deletar mais??" << std::endl;
}

void Menus::menu_delete_3()
{
    std::cout <<"Se sim, digite: SIM" << std::endl;
    std::cout <<"Se não, digite: PARE" << std::endl;
}

void Menus::menu_generic_line(const std::string &meter_line)
{
    std::cout<<" Linha de medidores " << meter_line << std::endl;
}

void Menus::menu_add_meter()
{
    std::cout << "Qual o medidor você gostaria de adicionar?" << std::endl;
}

void Menus::menu_delete_meter()
{
    std::cout << "Qual o medidor você gostaria de deletar?" << std::endl;
}

void Menus::menu_intro_switch()
{
    std::cout << "1.Linhas de Medidores\n2.Modelos dos Medidores de Energia\n3.Modelos da linha APOLO\n4.Modelos da linha CRONOS\n5.Modelos da linha ARES\n6.Modelos da linha ZEUS\n7.Adicionar Medidor de Energia\n8.Remover Medidor de Energia\n9.Limpar Tela\n10.EXIT"<< std::endl;
}

void Menus::menu_id()
{
    std::cout << "Digite o ID" << std::endl;
}

void Menus::menu_add()
{
    std::cout << "Quantos medidores você gostaria de adicionar?" << std::endl;
}

void Menus::menu_add_line()
{
    std::cout << "1.APOLO\n2.CRONOS\n3.ARES\n4.ZEUS\n" << std::endl;
}

void Menus::menu_invalid_option()
{
    std::cout << "Digite apenas linhas Válidas" << std::endl;
}

void Menus::menu_invalids_options()
{
    std::cout << "OPÇÃO INVÁLIDA!" << std::endl;
}

auto Menus::get_seletor(int n) -> Seletor
{
    switch (n) 
    {
    case 1:
        return Seletor::APOLO;
    case 2:
        return Seletor::CRONOS;
    case 3:
        return Seletor::ARES;
    case 4:
        return Seletor::ZEUS;
    case 5:
        return Seletor::SAIR;    
    }
    return Seletor::UNKNOWN;
}

auto Menus::get_seletor_2(int n) -> Selection
{
    switch(n)
    {
    case 1:
        return::Selection::LINHAS_DE_MEDIDORES;
    case 2:
        return::Selection::MODELOS_DOS_MEDIDORES_DE_ENERGIA;
    case 3:
        return::Selection::MODELO_DA_LINHA_APOLO;
    case 4:
        return::Selection::MODELO_DA_LINHA_CRONOS;
    case 5:
        return::Selection::MODELO_DA_LINHA_ARES;
    case 6:
        return::Selection::MODELO_DA_LINHA_ZEUS;
    case 7:
        return::Selection::ADICIONAR_MEDIDOR_DE_ENERGIA;
    case 8:
        return::Selection::REMOVER_MEDIDOR_DE_ENERGIA;
    case 9:
        return::Selection::LIMPAR_TELA;
    case 10:
        return::Selection::EXIT;
    }
    return::Selection::UNKNOWN;

};

auto Menus::get_int_by_user() ->int
{
    int n=0;
    std::string return_int;
    std::cin >>return_int;
    if (std::cin.fail())
    {
        std::cin.clear();
    }
    try
    {
        n = stoi(return_int);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return n;
}

std::string Menus::get_string_by_user()
{
    std::string in;
    std::cin>> in;
    if (std::cin.fail())
    {
        std::cin.clear();
    }
    return in;
}