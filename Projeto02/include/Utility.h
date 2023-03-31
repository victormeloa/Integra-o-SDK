#pragma once
#include "medidor_de_energia/medidor_de_energia.h"

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
    ADICIONAR_VARIOS_MEDIDORES_DE_ENERGIA,
    REMOVER_MEDIDOR_DE_ENERGIA,
    LIMPAR_TELA,
    EXIT,
    UNKNOWN

};

class Utility
{
public:
auto get_seletor(int n1) -> Seletor;
auto get_seletor_2(int n1) -> Selection;
auto converter_para_meterline(int n) -> MeterLine;
};


