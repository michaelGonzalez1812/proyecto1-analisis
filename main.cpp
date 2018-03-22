#include "algorithms/DeflateMethod.hpp"
#include "algorithms/LaguerreMethod.hpp"
#include "algorithms/MullerMethod.hpp"

int main(int argc, char *argv[]) {
//    cout << "Numero de parametros:   " << argc << endl;
//
//    for (int i = 0; i < argc; i++)
//        cout << "parametro " << i + 1 << ": " << atoi(argv[i]) + atoi(argv[i]) << endl;
    polynomial<double> a{{1.0, 2.0, 1.0}};
    polynomial<std::complex<double>> temp(a);
    std::complex<double> result = LaguerreMethod<std::complex<double>>(temp, 0.0 + 0.0i);
    std::cout << (result) << std::endl;
    vector<double> v=LaguerreFull<double>(a,0,1);
    //double result2=muller<double>(a,0.0,0.00001,0.00000001,100);
    std::cout << (v[2]) << std::endl;

    std::complex<float> result3 = LaguerreMethod<std::complex<float>>(a, float(0));
    //double result2=muller<double>(a,0.0,0.00001,0.00000001,100);
    std::cout << (result3) << std::endl;
    double kk=0.00001;
    polynomial<double> k = deflate(a,-1.0,kk);
    std::cout << (k) << std::endl;



    vector<double> vector1=MullerFull<double>(a,0,1);
    std::cout << (vector1[0]) << std::endl;
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
//float raiz = 2;
//float residuo = 5;
//
//cout << "Resultado:  " << algoritmos::deflate<float>(original, raiz, residuo) << endl;
//cout << "residuo:    " << residuo << endl;