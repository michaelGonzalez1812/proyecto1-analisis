//
// Created by mike on 13/03/18.
//

#ifndef PROYECTO_1_ROOTMULLER_H
#define PROYECTO_1_ROOTMULLER_H

#include "boost/math/tools/polynomial.hpp"

using namespace boost::math::tools;

/**
 * Encuentra las raices de un polinomio, por el metodo de muller.
 * @tparam T
 * @param poly Polinomio para encontrar la raiz.
 * @param xr Aproximacion de raiz inicial.
 * @param h Factor para calcular "x0" y "x1" iniciales. Recomendacion h = 0.1.
 * @param eps
 * @param maxit Maximo de iteraciones.
 * @return Raiz encontrada.
 */
template <typename T>
T muller (const polynomial<T>& poly, T xr, T h, T eps, T maxit){
    //TODO No funciona en raices negativas. Revisar
    //TODO implementarlo con raices complejas.

    T x2, x1, x0;
    T h0, h1, d0, d1, a, b, c;
    T rad, dxr, den;

    x2 = xr;
    x1 = xr + h*xr;
    x0 = xr - h*xr;

    for (int i = 0; i < maxit; ++i) {

        h0 = x1 + x0;
        h1 = x2 - x1;
        d0 = (poly.evaluate(x1) - poly.evaluate(x0)) / h0;
        d1 = (poly.evaluate(x2) - poly.evaluate(x1)) / h1;
        a = (d1 - d0) / (h1 + h0);
        b = a*h1 + d1;
        c = poly.evaluate(x2);

        rad = std::sqrt(b*b - 4*a*c);
        if(std::abs(b + rad) > std::abs(b - rad))
            den = b + rad;
        else
            den = b - rad;

        // TODO unir estas dos lineas
        dxr = -2*c / den;
        xr = x2 + dxr;

        if (std::abs(dxr) < eps*xr) break;

        x0 = x1;
        x1 = x2;
        x2 = xr;
    }
    return xr;
}

#endif //PROYECTO_1_ROOTMULLER_H
