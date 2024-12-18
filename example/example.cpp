#include <arba/meta/meta.hpp>
#include <arba/meta/version.hpp>
#include <cstdlib>
#include <iostream>

int main()
{
    std::cout << arba::meta::project_name() << std::endl;
    std::cout << "EXIT SUCCESS" << std::endl;
    return EXIT_SUCCESS;
}
