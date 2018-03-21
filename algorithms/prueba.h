//
// Created by mike on 19/03/18.
//

#ifndef PROYECTO_1_PRUEBA_H
#define PROYECTO_1_PRUEBA_H

#include "boost/math/tools/polynomial.hpp"
#include <complex>
#include <iostream>

using namespace std;
using namespace boost::math::tools; // for polynomial
template<typename T>
T prueba(polynomial<T> &parametro) {
    cout << parametro << endl;
}

#endif //PROYECTO_1_PRUEBA_H
