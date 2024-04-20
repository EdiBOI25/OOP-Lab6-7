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

        system("cls");
		RepoWithFile repo("data.txt");
		Service serv(repo);
        UI ui(serv);
        ui.run();
    }

    _CrtDumpMemoryLeaks();

    return 0;
}