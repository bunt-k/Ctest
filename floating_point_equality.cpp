#include <iostream>

int fpe()
{
    double f = 1.0;
    f += 0.000000000000000000000001;

    if (f == 1.0) {
        std::cout << "Same" << std::endl;
    }
    return 0;
}


