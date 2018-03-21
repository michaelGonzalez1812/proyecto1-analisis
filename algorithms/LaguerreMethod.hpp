//
// Created by Esteban Agüero Pérez  on 3/20/18.
//

#include <complex>
#include "boost/math/tools/polynomial.hpp"
#include <boost/type_traits/is_complex.hpp>

#ifndef PROYECTO_1_LAGUERREMETHOD_H
#define PROYECTO_1_LAGUERREMETHOD_H

using namespace boost::math;
using namespace boost::math::tools; // for polynomial
using namespace std::complex_literals;
using boost::lexical_cast;

/**
 * Metodo utilizado en el caso de coeficientes con coma flotante
 * @tparam T
 * @param poly
 * @param xr
 * @param eps
 * @param maxi
 * @return
 */

template<typename T>
std::complex<T> LaguerreMethod(const polynomial<std::complex<T>> &poly, std::complex<T> xr,
                               T eps = sqrt(std::numeric_limits<T>::epsilon()),
                               int maxi = std::numeric_limits<T>::digits,
                               typename std::enable_if<std::is_same<T, float>::value ||
                                                       std::is_same<T, double>::value>::type * = 0) {
    polynomial<T> frac = {0.0, 0.5, 0.25, 0.75, 0.13, 0.38, 0.62, 0.88, 1.0};
    std::complex<T> m(poly.degree(), 0);
    std::complex<T> dx, x1, g, gp, gm, h, b, d, f;
    std::complex<T> err;
    for (unsigned int it = 1; it <= maxi; it++) {
        b = poly.data()[m.real()];
        err = abs(b);
        d = std::complex<T>(0, 0);
        f = std::complex<T>(0, 0);
        for (int j = m.real() - 1; j >= 0; j--) {
            f = xr * f + d;// segunda derivada
            d = xr * d + b;// primera derivada
            b = xr * b + poly.data()[j];
            err = abs(b) + abs(xr) * err; // calculo de error
        }
        err *= eps;
        if (abs(b) < abs(err)) return xr;// ya se encontro la raiz

        //LaguerreMethod
        g = d / b;// G(x_k) = P'(x_k) / P(x_k). ([1], eq. 7.10)
        h = g * g - T(2) * f / b;// H(x_k) = G(x_k)^2 - (P''(x_k)/P(x_k)). ([1], eq. 7.11)
        gp = g + sqrt((m - T(1)) * (m * h - g * g));
        gm = g - sqrt((m - T(1)) * (m * h - g * g));
        if (abs(gp) < abs(gm)) gp = gm;
        if (std::max(abs(gp), abs(gm)) > 0) dx = m / gp;//([1], eq. 7.12)
        else dx = (T(1) + abs(xr)) * std::complex<T>(cos(T(1) * it), sin(T(1) * it));
        x1 = xr - dx;
        if ((xr.real() == x1.real()) && (xr.imag() == x1.imag())) return xr;
        if (it % 10) xr = x1;
        else xr = xr - std::complex<T>(frac[it / 10], 0) * dx;
    }
    return xr;
}

/**
 * Metodo utilizado en el caso de coeficientes complejos
 * @tparam T
 * @param poly
 * @param xr
 * @param eps
 * @param maxi
 * @return
 */

template<typename T>
T LaguerreMethod(const polynomial<T> &poly, T xr,
                 T eps = sqrt(std::numeric_limits<T>::epsilon()) / T(10),
                 int maxi = 100,
                 typename std::enable_if<boost::is_complex<T>::value, T>::type * = 0) {
    polynomial<double> frac = {0.0, 0.5, 0.25, 0.75, 0.13, 0.38, 0.62, 0.88, 1.0};
    T m(poly.degree(), 0);
    T dx, x1, g, gp, gm, h, b, d, f;
    T err;
    for (unsigned int it = 1; it <= maxi; it++) {
        b = poly.data()[m.real()];
        err = abs(b);
        d = T(0, 0);
        f = T(0, 0);
        for (int j = m.real() - 1; j >= 0; j--) {
            f = xr * f + d;// segunda derivada
            d = xr * d + b;// primera derivada
            b = xr * b + poly.data()[j];
            err = abs(b) + abs(xr) * err;// calculo del error
        }
        err *= eps;
        if (abs(b) < abs(err)) return xr;// se encontro la raiz
        g = d / b;// G(x_k) = P'(x_k) / P(x_k)
        h = g * g - T(2.0) * f / b;// H(x_k) = G(x_k)^2 - (P''(x_k)/P(x_k))
        gp = g + sqrt((m - T(1)) * (m * h - g * g));
        gm = g - sqrt((m - T(1)) * (m * h - g * g));
        if (abs(gp) < abs(gm)) gp = gm;
        if (std::max(abs(gp), abs(gm)) > 0) dx = m / gp;// compara cual denominador elegir
        else dx = (T(1.0) + abs(xr)) * T(cos(1 * it), sin(1.0 * it));
        x1 = xr - dx;
        // repite el numero maximo seleccionado de iteraciones
        if ((xr.real() == x1.real()) && (xr.imag() == x1.imag())) return xr;
        if (it % 10) xr = x1;
        else xr = xr - T(frac[it / 10], 0) * dx;
    }
    return xr;
}

template <typename T>
vector<T> LaguerreFull(const polynomial<T>& poly, T xr, bool pulido){
    polynomial<T> temp(poly);
    polynomial<std::complex<T>> tempcomplex(poly);
    polynomial<std::complex<T>> r;
    vector<T> raices;
    T raiz;
    std::complex<T> raiztemp;
    T resi=0;
    for(int i=0;i<poly.degree();i++){
        raiztemp= LaguerreMethod<T>(temp,xr);
        if(raiztemp.imag()==0){
            raices.push_back(raiz);
            temp=deflate(temp,raiz,resi);
            tempcomplex=polynomial<std::complex<T>>(temp);
        } else{
            std::cout << "Se encontro una raiz imaginaria: "<<raiztemp.real()<<"+"<<raiztemp.imag()<<"i" << std::endl;
            //tempcomplex=deflate2(temp,raiz,r);
        }
    }
    return raices;
}

#endif //PROYECTO_1_LAGUERREMETHOD_H
