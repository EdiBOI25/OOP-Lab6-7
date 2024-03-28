#include <iostream>
#include "tests.h"
#include "service.h"

int main()
{
    test_domain();
    test_repository();
    test_service();

    Subject s1("math", 5, "compulsory", "some dude");
    std::cout << s1 << '\n';

    return 0;
}

