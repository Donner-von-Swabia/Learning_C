
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

void top_line_draw()
// Draws the top line of the table
{
    cout << "\033[31;1;4m" ;
    for (int i=0; i<73; i++){
        printf("_");
    }
    rest_color();
}

