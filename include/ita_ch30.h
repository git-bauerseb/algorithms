#ifndef ITA_CH30_H
#define ITA_CH30_H

#include <iostream>
#include <initializer_list>
#include <memory>
#include <vector>


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

        static Polynomial add(const Polynomial& a, const Polynomial& b);

        static Polynomial simple_multiply(const Polynomial& a, const Polynomial& b);

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