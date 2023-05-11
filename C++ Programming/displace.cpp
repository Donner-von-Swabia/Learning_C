#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a , b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    float d, e, f ;
    d = (b * b) - (4 * a * c);
    e = (-1 * b) + d / (2*a);
    f =(-1 * b) - d/ (2*a);
    if (d == 0)
        cout << "repeated" << endl  << e;
    if (d > 0)
        cout << "complex" <<endl << e << endl << f;
    if (d < 0)
        cout << "real" << endl << e << endl << f;
        
    return 0;
}
