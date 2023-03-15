#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << "Select Operator \n";
    cout << " 0 = Add" << endl;
    cout << " 1 = Subtract" << endl;
    cout << " 2 = Multiply \n" <<" 3 = Division \n" << "4 = Modulus \n";
    int op;
    cin >> op;
    int first_number;
    int second_number;
    cout << "Enter first number \n";
    cin >> first_number;
    cout << "Enter second number \n";
    cin >> second_number;
    if (op == 0){
        int sum = first_number + second_number;
        cout << "\n" << sum;
    } 
    else if (op==1){
        int sum = first_number - second_number;
        cout << "\n" << sum;
    }
    else if (op==2){
        int product = first_number * second_number;
        cout << "\n" << product;
    }
    else if (op==3){
        double product = first_number/second_number;
        cout << "\n" << product;
    }
    else if (op==4){
        int remainder = first_number%second_number;
        cout << "\n" << remainder;
    }
    else{
        cout << "\n" <<" You entered an incorrect selector number, restart program";
    }
}