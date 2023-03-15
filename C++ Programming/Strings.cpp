#include <iostream>
#include <string>
using namespace std;

main (){
    string greeting = "Hello";
    string first_name = "Seth";
    string last_name = "Everett";
    // Concatenation
    string fullname = first_name +" "+ last_name;
    string fullname_append = first_name.append(last_name);
    cout << fullname << endl << fullname_append;
    // String Length
    string txt="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "The length of the alphabet is " << txt.length();
    cout << "This size of the alphabet is " << txt.size();
    // Using a string as a list
    string String_1 = "Hello";
    cout << endl << String_1[0];
    // Modify string like list
    String_1[0] = 'J';
    cout << endl << String_1;
    // Using Quotations within a print
    cout << endl << "We are the so-called \"Vikings\" from the north." << endl;
    cout << "It\'s alright." << endl;
    // Tab and New Line
    cout << "\t This is the beginning of the end \n";
    // User String Input
    cout <<"What is your name? \n";
    cin >> first_name;
    cout <<"Your name is " << first_name << endl;
    getline (cin,fullname);
    cout << fullname << endl;
    


}