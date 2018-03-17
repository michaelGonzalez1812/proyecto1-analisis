#include "algorithms/deflate.h"
#include "algorithms/rootMuller.h"

using namespace boost::math::tools;
using namespace std;
using boost::lexical_cast;
using namespace boost::math;


int main()
{

    return 0;
}

// Prueba Muller -----------------------------------------------
//polynomial<double> a {{-18, 9, 7, 1, 1}}; //Polinomio para presentar resultados (especificaion).
//polynomial<std::complex<double>> b = a;
//
//const std::complex<double> XR = 0 - 0i;
//const std::complex<double> H = 0.0001 + 0.0i;
//
//cout << "raiz encontrada:   " << muller<double>(b, XR, XR, H, 100) << endl;

//Prueba deflacion ---------------------------------------------
//const boost::array<float, 3> factoresOrig = {{-6, 1, 1}};
//polynomial<float> original(factoresOrig.begin(), factoresOrig.end());
//polynomial<float> original2(factoresOrig.begin(), factoresOrig.end());
//float raiz = 2;
//cout << "Resultado:  " << algoritmos::deflate<float>(original, raiz, original2) << endl;