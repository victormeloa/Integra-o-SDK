#include "Utility.h"

auto Utility::get_seletor(int n) -> Seletor
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

auto Utility::get_seletor_2(int n) -> Selection
{
    switch (n)
    {
    case 1:
        return ::Selection::LINHAS_DE_MEDIDORES;
    case 2:
        return ::Selection::MODELOS_DOS_MEDIDORES_DE_ENERGIA;
    case 3:
        return ::Selection::MODELO_DA_LINHA_APOLO;
    case 4:
        return ::Selection::MODELO_DA_LINHA_CRONOS;
    case 5:
        return ::Selection::MODELO_DA_LINHA_ARES;
    case 6:
        return ::Selection::MODELO_DA_LINHA_ZEUS;
    case 7:
        return ::Selection::ADICIONAR_MEDIDOR_DE_ENERGIA;
    case 8:
        return ::Selection::ADICIONAR_VARIOS_MEDIDORES_DE_ENERGIA;
    case 9:
        return ::Selection::REMOVER_MEDIDOR_DE_ENERGIA;
    case 10:
        return ::Selection::LIMPAR_TELA;
    case 11:
        return ::Selection::EXIT;
    }
    return ::Selection::UNKNOWN;

} 

auto Utility::converter_para_meterline(int n) -> MeterLine
{
    switch (n)
    {
    case 1:
        return MeterLine::APOLO;
    case 2:
        return MeterLine::ARES;
    case 3:
        return MeterLine::CRONOS;
    case 4:
        return MeterLine::ZEUS;
    }
    return MeterLine::UNKNOWN;
}