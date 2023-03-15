#pragma once
#include "medidor_de_energia.h"
#include <string>

enum class Seletor
{
    APOLO,
    CRONOS,
    ARES,
    ZEUS,
    SAIR,
    UNKNOWN
};


enum class Selection
{
    LINHAS_DE_MEDIDORES,
    MODELOS_DOS_MEDIDORES_DE_ENERGIA,
    MODELO_DA_LINHA_APOLO,
    MODELO_DA_LINHA_CRONOS,
    MODELO_DA_LINHA_ARES,
    MODELO_DA_LINHA_ZEUS,
    ADICIONAR_MEDIDOR_DE_ENERGIA,
    REMOVER_MEDIDOR_DE_ENERGIA,
    LIMPAR_TELA,
    EXIT,
    UNKNOWN

};

class Menus
{
    public:
        void menu_seletor();    
        void menu_insercao();
        void menu_intro();
        void menu_seperador();
        auto get_seletor(int n1) -> Seletor;
        auto get_seletor_2(int n1) -> Selection;
        auto get_int_by_user() -> int;
        std::string get_string_by_user();
        void menu_delete();
        void menu_delete_2();
        void menu_delete_3();
        void menu_add_meter();
        void menu_delete_meter();
        void menu_intro_switch();
        void menu_generic_line(const std::string &meter_line);
        void menu_id();
        void menu_add();
        void menu_add_line();
        void menu_invalid_option();
        void menu_invalids_options();
};