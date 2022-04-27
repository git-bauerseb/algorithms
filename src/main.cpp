#include <iostream>

#include "../include/fft.h"
#include "../include/ita_ch30.h"


int main(int argc, char** argv) {
    
    Polynomial A{4};
    Polynomial B{4};
    A.set_coefficients({9,-10,7,6});
    B.set_coefficients({-5,4,0,-2});

    Polynomial C = Polynomial::fft_multiply(A,B);
    std::cout << C << "\n";


    return 0;
}