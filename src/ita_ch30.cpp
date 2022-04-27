#include "../include/ita_ch30.h"

Polynomial Polynomial::add(const Polynomial& a, const Polynomial& b) {
    Polynomial c{a.degree()};

    for (int i = 0; i < c.degree(); i++) {
        c[i] = a[i] + b[i];
    }

    return c;
}


Polynomial Polynomial::simple_multiply(const Polynomial& a, const Polynomial& b) {
    Polynomial c{a.degree() + b.degree()};

    for (int i = 0; i < c.degree(); i++) {
        int c_sum = 0;

        for (int k = 0; k <= i; k++) {
            if (k < a.degree() && (i-k) < b.degree()) {
                c_sum += a[k]*b[i-k];
            }
        }

        c[i] = c_sum;
    }

    return c;
}

int Polynomial::evaluate_horner(int x0) const {
    int val = (*this)[degree()-1] * x0;
    
    for (int i = degree()-2; i > 0; i--) {
        val = (val + (*this)[i])*x0;
    }

    return val + (*this)[0];
}

Polynomial Polynomial::n_point_interpolation(std::vector<std::pair<int,int>> points) {
    Polynomial a{points.size()};
    return a;
}


static int next_power_of_two(int l) {
    int k = 1;

    while (k < l) {
        k <<= 1;
    }

    return k;
}

Polynomial Polynomial::fft_multiply(const Polynomial& a, const Polynomial& b) {

    int k = next_power_of_two(a.degree() * 2);

    std::vector<std::complex<float>> a_coeff;
    a_coeff.resize(k);
    std::fill(a_coeff.begin(), a_coeff.end(), 0);

    std::vector<std::complex<float>> b_coeff;
    b_coeff.resize(k);
    std::fill(b_coeff.begin(), b_coeff.end(), 0);

    for (int i = 0; i < a.degree(); i++) {
        a_coeff[i] = float{a[i]};
        b_coeff[i] = float{b[i]};
    }

    auto y1 = recursive_fft(a_coeff);
    auto y2 = recursive_fft(b_coeff);

    for (int i = 0; i < y1.size(); i++) {
        y1[i] = y1[i] * y2[i];
    }

    auto c_result = inverse_recursive_fft(y1);

    Polynomial c{a.degree() + b.degree()};

    for (int i = 0; i < c.degree(); i++) {
        float val = c_result[i].real() / k;
        c[i] = std::round(val);
    }

    return c;
}