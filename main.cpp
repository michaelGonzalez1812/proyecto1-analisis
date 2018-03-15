#include "algorithms/deflate.h"
#include "algorithms/rootMuller.h"

using namespace boost::math::tools;
using namespace std;
using boost::lexical_cast;
using namespace boost::math;


int main()
{
    const boost::array<float, 3> factores = {{6, -5, 1}};
    polynomial<float> polinomio(factores.begin(), factores.end());

    cout << "raiz encontrada:   " <<
         muller<float>(polinomio, 1, 0.1, 0.0001, 100) << endl;

    return 0;
}

//const boost::array<float, 3> factoresOrig = {{-6, 1, 1}};
//polynomial<float> original(factoresOrig.begin(), factoresOrig.end());
//polynomial<float> original2(factoresOrig.begin(), factoresOrig.end());
//float raiz = 2;
//cout << "Resultado:  " << algoritmos::deflate<float>(original, raiz, original2) << endl;