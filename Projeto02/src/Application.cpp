#include "medidor_de_energia/ares.h"
#include "medidor_de_energia/zeus.h"
#include "medidor_de_energia/cronos.h"
#include "medidor_de_energia/apolo.h"
#include "medidor_de_energia/medidor_de_energia.h"
#include "Application.h"
#include "fabrica_de_medidor.h"

Application::Application()
{
}

void Application::run_app()
{
    Utility selecao;
    bool run = true;
    while (run)
    {
        my_menu.menu_intro_switch();
        int numero_da_selecao = my_menu.get_int_by_user();
        Selection(selection) = selecao.get_seletor_2(numero_da_selecao);
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
            my_menu.print_meter_list(ees.get_lista_de_medidores_por_linha(MeterLine::APOLO));
            break;

        case Selection::MODELO_DA_LINHA_CRONOS:
            my_menu.menu_generic_line("CRONOS");
            my_menu.menu_seperador();
            my_menu.print_meter_list(ees.get_lista_de_medidores_por_linha(MeterLine::CRONOS));
            break;

        case Selection::MODELO_DA_LINHA_ARES:
            my_menu.menu_generic_line("ARES");
            my_menu.menu_seperador();
            my_menu.print_meter_list(ees.get_lista_de_medidores_por_linha(MeterLine::ARES));
            break;

        case Selection::MODELO_DA_LINHA_ZEUS:
            my_menu.menu_generic_line("ZEUS");
            my_menu.menu_seperador();
            my_menu.print_meter_list(ees.get_lista_de_medidores_por_linha(MeterLine::ZEUS));
            break;

        case Selection::ADICIONAR_MEDIDOR_DE_ENERGIA:
            add_meter();
            break;
        case Selection::ADICIONAR_VARIOS_MEDIDORES_DE_ENERGIA:
            switch_adicionar_medidor();
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
    Utility converter;

    while (run_app)
    {
        try
        {
            my_menu.menu_seletor();
            int numero_da_selecao = my_menu.get_int_by_user();

            if(numero_da_selecao == 5)
            {
                run_app=false;
                break;
            }
            auto meter_line = converter.converter_para_meterline(numero_da_selecao);
            my_menu.menu_model();
            model = my_menu.get_string_by_user();
            my_menu.menu_id();
            id = my_menu.get_int_by_user();
            auto meter = create_meter(meter_line, model, id);
            ees.adicionar_medidor(*meter);
            mostrar_lista_de_medidores();
        }
        
        catch (const std::exception &e)
        {
            run_app = false;
        }
    }
}

void Application::add_multiples_meters(MeterLine type)
{
    int num = my_menu.get_int_by_user();
    std::string model;
    int id;
    for (int i = 0; i < num; i++)
    {
        my_menu.menu_insercao();
        model = my_menu.get_string_by_user();
        my_menu.menu_id();
        id = my_menu.get_int_by_user();
        auto meter = create_meter(type, model, id);
        ees.adicionar_medidor(*meter);
    }

    mostrar_lista_de_medidores();
    
}

void Application::mostrar_lista_de_medidores()
{
    my_menu.menu_seperador();
    my_menu.print_meter_list(ees.get_lista_de_medidores());
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
}

void Application::switch_adicionar_medidor()
{   
    my_menu.menu_add_meter();
    my_menu.menu_add_line();
    int n = my_menu.get_int_by_user();
    my_menu.menu_add();
    switch (n)
    {
    case 1:
        add_multiples_meters(MeterLine::APOLO);
        break;
    case 2:
        add_multiples_meters(MeterLine::CRONOS);
        break;
    case 3:
        add_multiples_meters(MeterLine::ARES);
        break;
    case 4:
        add_multiples_meters(MeterLine::ZEUS);
        break;
    }
}

