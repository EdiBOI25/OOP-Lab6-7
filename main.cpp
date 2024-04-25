#include <iostream>
#include "tests.h"
#include "UI.h"

// TODO: ai poza pe telefon cu ce e de facut
// vezi cu getAll ala din RepoLab
// de testat repoLab
// de bagat probabilitatea (sa arunce exceptie)
// vezi cum poti testa
// incearca cu repoLab in main

int main()
{

    {
        test_domain();
        test_cart();
        //test_dynamic_array();
        test_repository();
        test_repo_lab();
        test_service();

        system("cls");
		//RepoWithFile repo("data.txt");
        RepoLab repo(0.5);
		Service serv(repo);
        UI ui(serv);
        ui.run();
    }

    _CrtDumpMemoryLeaks();

    return 0;
}