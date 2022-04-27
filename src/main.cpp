#include <iostream>
#include "../include/ita_ch30.h"

int main(int argc, char** argv) {
    Polynomial a{4};
    Polynomial b{4};
    a.set_coefficients({9,-10,7,6});
    b.set_coefficients({-5,4,0,-2});

    Polynomial c = Polynomial::simple_multiply(a,b);
    // std::cout << c << "\n";

    std::cout << a.evaluate_horner(12) << "\n";

    return 0;
}