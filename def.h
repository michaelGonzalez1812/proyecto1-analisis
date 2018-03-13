//
// Created by mike on 11/03/18.
//



#ifndef DEFA
#define DEFA

#include <iostream>
#include "boost/math/tools/polynomial.hpp"

using namespace boost::math::tools;
using namespace std;

namespace algoritmos {

/***
 * Para raices reale
 * Deflacion polinomial
 * @tparam T
 * @param poly Polinomio a deflacionar
 * @param root Polinomio de la raiz a eliminar
 * @param residuo **Por definir**
 * @return Polinomio deflacionado
 */
    template <typename T>
    polynomial<T> deflate(const polynomial<T>& poly, const T& root, polynomial<T>& residuo) {
        polynomial<T> resultado = poly;

        T r = resultado[ resultado.degree() ];
        resultado[ resultado.degree() ] = 0;
        T auxiliar;

        for(int i = resultado.degree() - 1; i >= 0; --i){
            auxiliar = resultado[i];
            resultado[i] = r;
            r = auxiliar + r * root;
        }

        return resultado;
    }

    

}
#endif //PROYECTO_1_DEFALT_H
