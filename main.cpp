#include <iostream>
#include "tests.h"
#include "UI.h"

int main()
{
    {
        test_domain();
        test_cart();
        //test_dynamic_array();
        test_repository();
        test_service();

        UI ui{};
        system("cls");
        ui.run();
    }

    _CrtDumpMemoryLeaks();

    return 0;
}