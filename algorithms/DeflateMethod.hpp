//
// Created by mike on 11/03/18.
//

#ifndef DEFA
#define DEFA

#include <iostream>
#include <complex>
#include "boost/math/tools/polynomial.hpp"

using namespace boost::math::tools;
using namespace std;


/***
 * Para raices reale
 * Deflacion polinomial
 * @tparam T
 * @param poly Polinomio a deflacionar
 * @param root Polinomio de la raiz a eliminar
 * @param residuo **Por definir**
 * @return Polinomio deflacionado
 */
template<typename T>
polynomial<T> deflate(const polynomial<T> &poly, const T &root, T residuo) {
    polynomial<T> resultado = poly;
    residuo = resultado[resultado.degree()];
    resultado[resultado.degree()] = T(0);
    T auxiliar;
    for (int i = resultado.degree() - 1; i >= 0; --i) {
        auxiliar = resultado[i];
        resultado[i] = residuo;
        residuo = auxiliar + residuo * root;
    }

    return resultado;
}

/**
 * Delacionar entre un polinomio de orden superior. Util para raices complejas.
 * @tparam T
 * @param poly Polinomio a deflacionar.
 * @param root laiz a deflacionar.
 * @param residuo
 * @return polinomio deflacionado
 */
template<typename T>
polynomial<std::complex<T>> deflate2(const polynomial<std::complex<T>> &poly,
                                     const std::complex<T> &root, polynomial<std::complex<T>> residuo) {

    polynomial<T> divisor{{root.imag() * root.imag(), 0, 1}};
    polynomial<std::complex<T>> divisorC = divisor;

    // TODO buscar una forma de instanciarlo de una forma como boost::array<std::complex<T>, poly.degree()> --> da error
    boost::array<std::complex<T>, 10> resultadoArrayAux = {};
    boost::array<T, 10> resultadoArray = {};
    for (int i = 0; i < poly.degree(); ++i) {
        residuo[i] = poly[i];
        resultadoArrayAux[i] = 0;
    }

    for (int i = poly.degree() - 2; i >= 0; --i) {
        resultadoArrayAux[i + 1] = residuo[2 + i] / divisorC[divisorC.degree()];
        for (int j = 2 + i - 1; j >= i; --j) {
            residuo[j] = residuo[j] -
                         resultadoArrayAux[i + 1] * divisorC[j - i]; //comparar esta linea con el pseudocodigo
        }
    }

    for (int i = 2; i <= poly.degree(); ++i) {
        residuo[i] = 0;
    }

    for (int i = 0; i <= poly.degree() - 2; ++i) {
        resultadoArray[i] = resultadoArrayAux[i + 1].real();
    }

    polynomial<T> resultadoAux(resultadoArray.begin(), resultadoArray.end());
    polynomial<std::complex<T>> resultado = resultadoAux;

    return resultado;
}

#endif //PROYECTO_1_DEFALT_H
