//
// Created by mike on 13/03/18.
//

#ifndef PROYECTO_1_ROOTMULLER_H
#define PROYECTO_1_ROOTMULLER_H

#include "boost/math/tools/polynomial.hpp"
#include <complex>
#include <typeinfo>
#include <iostream>
#include <type_traits>

using namespace std;
using namespace boost::math::tools;

/**
 * Encuentra las raices de un polinomio, por el metodo de muller.
 * @tparam T
 * @param poly Polinomio para encontrar la raiz.
 * @param xr Aproximacion de raiz inicial.
 * @param h Factor para calcular "x0" y "x1" iniciales.
 * @param eps
 * @param maxit Maximo de iteraciones.
 * @return Raiz encontrada.
 */
template<typename T>
T muller(const polynomial<T> &poly, T xr, T h, T eps, int maxit) {

    polynomial<T> polinomio = poly;

    const T CUATRO = 4.0;
    const T DOS = 2.0;
    const T CERO = 0.0;
    const T UNO_PUNTO_CINCO = 1.5;
    const T UNO = 1.0;

    T x2, x1, x0;
    T h0, h1, d0, d1, a, b, c;
    T rad, den, dxr;

    x2 = xr;
    x1 = xr == CERO ? UNO_PUNTO_CINCO : xr + h * xr;
    x0 = xr == CERO ? -UNO : xr - h * xr;

    for (int i = 0; i < maxit; ++i) {
        h0 = x1 + x0;
        h1 = x2 - x1;
        d0 = (polinomio.evaluate(x1) - polinomio.evaluate(x0)) / h0;
        d1 = (polinomio.evaluate(x2) - polinomio.evaluate(x1)) / h1;
        a = (d1 - d0) / (h1 + h0);
        b = a * h1 + d1;
        c = polinomio.evaluate(x2);

        rad = std::sqrt(b * b - CUATRO * a * c);
        if (std::abs(b + rad) > std::abs(b - rad))
            den = b + rad;
        else
            den = b - rad;

        dxr = -DOS * c / den;
        xr = x2 + dxr;

        if (std::abs(dxr) < std::abs(eps * xr)) break;

        x0 = x1;
        x1 = x2;
        x2 = xr;
    }

    return xr;
}

#endif //PROYECTO_1_ROOTMULLER_H
