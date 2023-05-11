#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
void clear_screen()
{// Clears everything out out of the console
    system("cls");
}

void rest_color()
// Resets all text attributes
{
    cout <<"\033[0m" << endl;
}
