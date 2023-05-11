#include <iostream>

using namespace std;

int function()
{
    return 0;
}

void functiona()
{
    cout << "Outputting" << endl;
}

void functionb();

int main()
{   
    function();
    functiona();
    functionb();
    return 0;
}

void functionb()
{
    cout <<"testing output" << endl;
}