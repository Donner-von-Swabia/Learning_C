#include <iostream>
#include <string>

using namespace std;

int main()
{
    int dividend, divisor, quotient;
    string input_string = "The input is not an integer";
    try
    {
        cout << "Enter the dividend" << endl;
        cin >> dividend;

        cout <<"Enter the divisor" << endl;
        cin >> divisor;

        if (divisor == 0)
            throw divisor;
        else if (divisor < 0)
            throw string("Negative divisor");
        else if (!cin)
            throw input_string;
        
        quotient = dividend / divisor;

        cout << "Quotient: " << quotient << endl;
    }
    catch (int x)
    {
        cout << " Division by " << x << endl;
    }
    catch (string s)
    {
        cout << " s " << endl;
    }
    catch (...)
    {
        cout <<"Critical Error" << endl;
    }
    return 0;
}