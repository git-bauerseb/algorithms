#ifndef ITA_CH30_H
#define ITA_CH30_H

#include <iostream>
#include <initializer_list>
#include <memory>
#include <vector>
#include <complex>
#include <cmath>

#include "fft.h"


class Polynomial {
    public:
        Polynomial(int degree) : m_size{degree} {
            m_coefs = new int[degree];

            for (int i = 0; i < degree; i++) {
                m_coefs[i] = 0;
            }
        }

        int& operator[](int idx) const {
            return m_coefs[idx];
        }

        int degree() const {
            return m_size;
        }

        void set_coefficients(std::vector<int> coeffs) {
            std::copy(coeffs.begin(), coeffs.end(), m_coefs);
        }

        /*
            Evaluate polynomial using Horner's rule.
        */
        int evaluate_horner(int x0) const;

        /*
            Give the unique polynomial that satisfies the conditions of the point-value pairs.
            Uses Lagrange's formula for interpolation.
        */
        static Polynomial n_point_interpolation(std::vector<std::pair<int,int>> points);

        static Polynomial add(const Polynomial& a, const Polynomial& b);

        /*
            Uses simple looping of coefficients to multiply the two polynomials.
            Runtime is Theta(n^2).
        */
        static Polynomial simple_multiply(const Polynomial& a, const Polynomial& b);

        /*
            Uses Discrete Fouriert Transform to multiply two polynomials.
            Because FFT is used for computation of DFT, the runtime (theoretically) is Theta(n * log n).

            Practically, because of the recursive/non-optimized implementation it is slower and numerically
            unstable.
        */
        static Polynomial fft_multiply(const Polynomial& a, const Polynomial& b);

    private:
        int m_size;
        int* m_coefs;
};

inline std::ostream& operator<<(std::ostream& o, const Polynomial& p) {
    for (int i = p.degree() - 1; i >= 0; i--) {
        if (p[i] != 0) {
            if (i == 0) {
                o << p[i];
            } else {
                o << p[i] << "x^" << i << " + ";
            }
        }
    }

    return o;
}


#endif