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