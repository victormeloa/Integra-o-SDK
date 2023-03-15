
#include "Application.h"
#include <locale.h>

int main()
{   
    setlocale(LC_ALL, "pt_BR.UTF-8");
    Application app;

    app.run_app();
    return 0;
}