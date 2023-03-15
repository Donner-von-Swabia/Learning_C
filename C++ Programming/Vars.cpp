#include <iostream>
using namespace std;

int main(){
    int integer = 15;
    double floating = 12.233;
    char character = 'B';
    string str = "Hello World";
    bool Boolean = true;
    cout << integer;
    cout << floating;
    cout << character;
    cout << str;
    cout << Boolean;
    integer = 10;
    cout << integer;
    cout << "I am" << integer << "I have" << floating << "My fav. letter is" << character << "I say" << str <<"Are you" << Boolean;
    return 0;

}