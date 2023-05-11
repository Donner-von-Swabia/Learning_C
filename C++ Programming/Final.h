#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
void clear_screen()
{
    system("cls");
}

void rest_color()
{
    cout <<"\033[0m" << endl;
}

void top_line_draw()
{
    cout << "\033[31;1;4m" ;
    for (int i=0; i<73; i++){
        printf("_");
    }
    rest_color();
}

