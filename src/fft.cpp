#include "../include/fft.h"

static std::complex<float> pi = std::complex<float>{PI,0};
static std::complex<float> i = std::complex<float>{0,1};

std::vector<std::complex<float>> recursive_fft(std::vector<std::complex<float>> a) {
    // Assumption that n is power of 2
    int n = a.size();

    std::vector<std::complex<float>> result;

    if (n == 1) {
        result.push_back(std::complex<float>{a[0]});
        return result;
    }

    std::complex<float> omega_n = std::exp(float{2} * pi * i / float{n});
    std::complex<float> omega = std::complex<float>{1,0};

    std::vector<std::complex<float>> a_0;
    std::vector<std::complex<float>> a_1;

    for (int i = 0; i < n / 2; i++) {
        a_0.push_back(a[2*i]);
        a_1.push_back(a[2*i+1]);
    }

    std::vector<std::complex<float>> y_0 = recursive_fft(a_0);
    std::vector<std::complex<float>> y_1 = recursive_fft(a_1);
    std::vector<std::complex<float>> y;
    y.resize(n);

    std::fill(y.begin(), y.end(), 0);

    
    
    for (int k = 0; k <= n/2 - 1; k++) {
        y[k] = y_0[k] + omega * y_1[k];
        y[k + n / 2] = y_0[k] - omega * y_1[k];
        omega = omega * omega_n;
    }
    
    return y;
}

std::vector<std::complex<float>> inverse_recursive_fft(std::vector<std::complex<float>> a) {
    // Assumption that n is power of 2
    int n = a.size();

    std::vector<std::complex<float>> result;

    if (n == 1) {
        result.push_back(std::complex<float>{a[0]});
        return result;
    }

    std::complex<float> omega_n = float{1} / (std::exp(float{2} * pi * i / float{n}));
    std::complex<float> omega = std::complex<float>{1,0};

    std::vector<std::complex<float>> a_0;
    std::vector<std::complex<float>> a_1;


    for (int i = 0; i < n / 2; i++) {
        a_0.push_back(a[2*i]);
        a_1.push_back(a[2*i+1]);
    }

    std::vector<std::complex<float>> y_0 = inverse_recursive_fft(a_0);
    std::vector<std::complex<float>> y_1 = inverse_recursive_fft(a_1);
    std::vector<std::complex<float>> y;
    y.resize(n);

    std::fill(y.begin(), y.end(), 0);
    std::swap(a,y);
    
    
    for (int k = 0; k <= n/2 - 1; k++) {
        y[k] = (y_0[k] + omega * y_1[k]);
        y[k + n / 2] = (y_0[k] - omega * y_1[k]);
        omega = omega * omega_n;
    }

    
    return y;
}