#include "algorithms/deflate.h"
#include "algorithms/rootMuller.h"
#include <cstdlib>
#include "algorithms/prueba.h"
#include <typeinfo>

using namespace boost::math::tools;
using namespace std;
using boost::lexical_cast;
using namespace boost::math;


int main(int argc, char * argv [])
{

    return 0;
}

// Prueba Muller -----------------------------------------------
//polynomial<double> a {{-18, 9, 7, 1, 1}}; //Polinomio para presentar resultados (especificaion).
//polynomial<std::complex<double>> b = a;
//
//const double XR =-3;
//const double H = 0.0001;
//
//cout << "raiz encontrada:   " << muller<double>(a, XR, H, 0.0001, 100) << endl;

//Prueba deflacion ---------------------------------------------
//const boost::array<float, 3> factoresOrig = {{-6, 1, 1}};
//polynomial<float> original(factoresOrig.begin(), factoresOrig.end());
//float raiz = 2;
//float residuo = 5;
//
//cout << "Resultado:  " << algoritmos::deflate<float>(original, raiz, residuo) << endl;
//cout << "residuo:    " << residuo << endl;

//Prueba deflacion 2--------------------------------------------
//const boost::array<float, 5> dividendoFactores = {{-18, 9, 7, 1, 1}};
//polynomial<float> dividendoAux(dividendoFactores.begin(), dividendoFactores.end());
//polynomial<std::complex<float>> dividendo = dividendoAux;
//const std::complex<float> raiz = 0+3i;
//const boost::array<float, 4> residuoFactores = {{1, 1, 1, 1}};
//polynomial<float> residuoAux(dividendoFactores.begin(), dividendoFactores.end());
//polynomial<std::complex<float>> residuo = residuoAux;
//
//cout << "Resultado:  " << algoritmos::deflate2<float>(dividendo, raiz, residuo) << endl;
//cout << "residuo:    " << residuo << endl;
//cout << "dividendo:  " << dividendo << endl;
//
//#include <iostream>
//#include <type_traits>
//#include <typeinfo>
//
//int main()
//{
//    typedef std::conditional<true, int, double>::type Type1;
//    typedef std::conditional<false, int, double>::type Type2;
//    typedef std::conditional<sizeof(int) >= sizeof(double), int, double>::type Type3;
//
//    std::cout << typeid(Type1).name() << '\n';
//    std::cout << typeid(Type2).name() << '\n';
//    std::cout << typeid(Type3).name() << '\n';
//}

