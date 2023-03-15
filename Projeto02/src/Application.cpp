#include "EletraEnergySolutions.h"
#include "medidor_de_energia/ares.h"
#include "medidor_de_energia/zeus.h"
#include "medidor_de_energia/cronos.h"
#include "medidor_de_energia/apolo.h"
#include "medidor_de_energia.h"
#include "Application.h"
#include <string>
#include <iostream>
#include <list>

Application::Application()
    : output_file(file_path, std::ios::app)
{
}

void Application::run_app()
{
    bool run = true;
    while (run)
    {
        my_menu.menu_intro_switch();
        int numero_da_selecao = my_menu.get_int_by_user();
        Selection(selection) = my_menu.get_seletor_2(numero_da_selecao);
        switch (selection)
        {
        case Selection::LINHAS_DE_MEDIDORES:
            my_menu.menu_add_line();
            break;

        case Selection::MODELOS_DOS_MEDIDORES_DE_ENERGIA:
            mostrar_lista_de_medidores();
            break;

        case Selection::MODELO_DA_LINHA_APOLO:
            my_menu.menu_generic_line("APOLO");
            my_menu.menu_seperador();
            ees.list_meters_by_line(MeterLine::APOLO);
            break;

        case Selection::MODELO_DA_LINHA_CRONOS:
            my_menu.menu_generic_line("CRONOS");
            my_menu.menu_seperador();
            ees.list_meters_by_line(MeterLine::CRONOS);
            break;

        case Selection::MODELO_DA_LINHA_ARES:
            my_menu.menu_generic_line("ARES");
            my_menu.menu_seperador();
            ees.list_meters_by_line(MeterLine::ARES);
            break;

        case Selection::MODELO_DA_LINHA_ZEUS:
            my_menu.menu_generic_line("ZEUS");
            my_menu.menu_seperador();
            ees.list_meters_by_line(MeterLine::ZEUS);
            break;

        case Selection::ADICIONAR_MEDIDOR_DE_ENERGIA:
            add_meter();
            break;
        case Selection::REMOVER_MEDIDOR_DE_ENERGIA:
            delete_meter();
            break;
        case Selection::LIMPAR_TELA:
            clear();
            break;
        case Selection::EXIT:
            run = false;
            break;
        case Selection::UNKNOWN:
            my_menu.menu_invalids_options();
            break;
        }
    }
}

void Application::add_meter()
{
    std::string model;
    int id;
    bool run_app = true;

    while (run_app)
    {

        my_menu.menu_seletor();
        int numero_da_selecao = 0;
        numero_da_selecao = my_menu.get_int_by_user();
        Seletor seletor = my_menu.get_seletor(numero_da_selecao);

        switch (seletor)
        {
        case Seletor::APOLO:
            add_multiples_meters(MeterLine::APOLO);
            break;

        case Seletor::CRONOS:
            add_multiples_meters(MeterLine::CRONOS);
            break;

        case Seletor::ARES:
            add_multiples_meters(MeterLine::ARES);
            break;

        case Seletor::ZEUS:
            add_multiples_meters(MeterLine::ZEUS);
            break;
        case Seletor::SAIR:
            run_app = false;
            break;
        case Seletor::UNKNOWN:
            my_menu.menu_invalid_option();
            break;
        }
    }
}

void Application::add_multiples_meters(MeterLine type)
{
    my_menu.menu_add();
    int num = my_menu.get_int_by_user();

    std::string model;
    int id;

    for (int i = 0; i < num; i++)
    {
        my_menu.menu_insercao();
        model = my_menu.get_string_by_user();
        my_menu.menu_id();
        id = my_menu.get_int_by_user();
        ees.add_meter(type, model, id);
        my_menu.menu_intro_switch();
    }

    mostrar_lista_de_medidores();
    add_meter();
    run_app();
}

void Application::mostrar_lista_de_medidores()
{

    my_menu.menu_seperador();
    for (const auto &meter : ees.get_lista_de_medidores())
    {
        std::cout << meter.get_id() << " -------- " << meter.mostrar_informacoes_do_medidor() << std::endl;
    }
}

void Application::delete_meter()
{
    std::string m;
    while (m != "pare")
    {
        int d;
        my_menu.menu_delete();
        d = my_menu.get_int_by_user();

        for (auto it = ees.get_lista_de_medidores().begin(); it != ees.get_lista_de_medidores().end(); it++)
        {
            if (it->get_id() == d)
            {
                it = ees.get_lista_de_medidores().erase(it);
                break;
            }
        }
        my_menu.menu_delete_2();
        my_menu.menu_delete_3();
        mostrar_lista_de_medidores();
        m = my_menu.get_string_by_user();

        for (int i = 0; i < m.size(); i++)
        {
            m[i] = tolower(m[i]);
        }
    }
}

void Application::clear()
{
    system("cls");
    my_menu.menu_intro_switch();
}
