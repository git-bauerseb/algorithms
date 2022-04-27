#ifndef FFT_H
#define FFT_H

#include <complex>
#include <cmath>
#include <vector>

#define PI 3.14159265359

/*
    FFT to compute the Discrete Fourier Transform recursively.
*/
std::vector<std::complex<float>> recursive_fft(std::vector<std::complex<float>> a);

/*
    The inverse of the FFT. Note that after the result is obtained, every complex number
    needs to be divided by the size of the vector.
*/
std::vector<std::complex<float>> inverse_recursive_fft(std::vector<std::complex<float>> y);

#endif