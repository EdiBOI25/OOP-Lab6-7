#include <iostream>
#include "tests.h"
#include "UI.h"

// TODO: find subject, update subject, delete subject

int main()
{
    test_domain();
    test_repository();
    test_service();
    // system("cls");

    // Adding random subjects
    Repository repo{};
    repo.add(Subject("default3", 6, "compulsory", "some dude"));
    repo.add(Subject("default1", 2, "optional", "other dude"));
    repo.add(Subject("default4", 5, "compulsory", "some other dude"));
    repo.add(Subject("default2", 10, "other", "yet another dude"));

    UI ui{Service(repo)};
    ui.run();

    return 0;
}

