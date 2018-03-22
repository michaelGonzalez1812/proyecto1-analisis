#include "algorithms/DeflateMethod.hpp"
#include "algorithms/LaguerreMethod.hpp"

int main(int argc, char *argv[]) {
    polynomial<double> a{{-18,9,7,1,1,}};
    vector<double> t=LaguerreFull<double>(a,0.0);
    for(int i=0;i<t.size();i++){
        std::cout<<t[i]<<std::endl;
    }
    return 0;
}