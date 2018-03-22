#include "algorithms/DeflateMethod.hpp"
#include "algorithms/LaguerreMethod.hpp"
#include "algorithms/MullerMethod.hpp"

int main(int argc, char *argv[]) {
    polynomial<float> poly{{1,0,1}};// x²+1=0
    vector<float> raices=LaguerreFull<float>(poly,0.0);
    for(int i=0;i<raices.size();i++){
        std::cout<<"Raiz encontrada: "<<raices[i]<<std::endl;
    }
}