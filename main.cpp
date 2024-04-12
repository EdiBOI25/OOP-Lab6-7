#include <iostream>
#include "tests.h"
#include "UI.h"

int main()
{
    test_domain();
    //test_dynamic_array();
    test_repository();
    test_service();

    UI ui{};
    system("cls");
    ui.run();

    return 0;
}