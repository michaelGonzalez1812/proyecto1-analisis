#include "def.h"

using namespace boost::math::tools;
using namespace std;
using boost::lexical_cast;
using namespace boost::math;

int main()
{
    const boost::array<float, 3> factoresOrig = {{-6, 1, 1}};
    polynomial<float> original(factoresOrig.begin(), factoresOrig.end());
    polynomial<float> original2(factoresOrig.begin(), factoresOrig.end());
    float raiz = 2;
    algoritmos::deflate<float>(original, raiz, original2);

    return 0;
}
