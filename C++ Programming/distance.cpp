#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a , b;
    float h , m;
    cin >> a;
    cin >> b;
    cin >> h;
    cin >> m;
    float d, e_time, a_distance, b_distance, total;
    e_time = h+ (m/60);
    a_distance = (e_time * a)*(e_time * a) ;
    b_distance = (e_time * b)*(e_time * b);
    total = a_distance + b_distance;
    d = sqrt(total);
    cout << d;
    return 0;
}
