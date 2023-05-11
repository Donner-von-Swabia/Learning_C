#include <iostream>
using namespace std;

int main(){
    int quant, choice;
    int Quantitiy_room=0,Quantitiy_pasta=0, Quantitiy_burger=0l, Quantitiy_noodles=0, Quantitiy_shake=0, Quantitiy_chicken=0;
    int Sold_room=0, Sold_pasta=0, Sold_burger=0, Sold_noodles=0, Sold_shake=0, Sold_chicken=0;
    int Price_room=0, Price_pasta=0, Price_burger=0, Price_noodles=0, Price_shake=0, Price_chicken=0;
    cout << "\t Quantity of items" << endl;
    cout << "Rooms avaliable" << endl;
    cin >> Quantitiy_room;
    cout <<"Pasta, Burgers, Noodels, Shakes, Chickens" << endl;
    cin >> Quantitiy_pasta >> Quantitiy_burger >> Quantitiy_noodles >> Quantitiy_shake >> Quantitiy_chicken;
    m:
    cout <<"Select from menu" << endl;
    cout <<"1) Rooms" << endl << "2) Pasta" << endl << "3) Burgers" << endl << "4) Noodles" << endl << "5) Shakes" << endl << "6) Chicken" << endl << "7) Admin Info" << endl << "8) Exit" << endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
            cout << "Enter number of rooms requested" << endl;
            cin >> quant;
            if (Quantitiy_room - Sold_room >= quant)
            {
                Sold_room = Sold_room + quant;
                Price_room = Price_room + quant* 50;
                cout << quant << " rooms have been alloted " << endl;
                break;
            }
            else
            {
                cout<< "Only " << Quantitiy_room - Sold_room << " remain available." << endl;
                break;
            }
        case 2:
            cout << "Enter number of Pasta requested" << endl;
            cin >> quant;
            if (Quantitiy_pasta - Sold_pasta >= quant)
            {
                Sold_pasta = Sold_pasta + quant;
                Price_pasta = Price_pasta + quant* 15;
                cout << quant << " pasta have been alloted " << endl;
                break;
            }
            else
            {
                cout<< "Only " << Quantitiy_pasta - Sold_pasta << " remain available." << endl;
                break;
            }
        case 3:
        cout << "Enter number of Burgers requested" << endl;
            cin >> quant;
            if (Quantitiy_burger - Sold_burger >= quant)
            {
                Sold_burger = Sold_burger + quant;
                Price_burger = Price_burger + quant* 12;
                cout << quant << " burger have been alloted " << endl;
                break;
            }
            else
            {
                cout<< "Only " << Quantitiy_burger - Sold_burger << " remain available." << endl;
                break;
            }
        case 4:
        cout << "Enter number of noodles requested" << endl;
            cin >> quant;
            if (Quantitiy_noodles - Sold_noodles >= quant)
            {
                Sold_noodles = Sold_noodles + quant;
                Price_noodles = Price_noodles + quant* 10;
                cout << quant << " rooms have been alloted " << endl;
                break;
            }
            else
            {
                cout<< "Only " << Quantitiy_noodles - Sold_noodles << " remain available." << endl;
                break;
            }
        case 5:
        cout << "Enter number of shakes requested" << endl;
            cin >> quant;
            if (Quantitiy_shake - Sold_shake >= quant)
            {
                Sold_shake = Sold_shake + quant;
                Price_shake = Price_shake + quant* 5;
                cout << quant << " shake have been alloted " << endl;
                break;
            }
            else
            {
                cout<< "Only " << Quantitiy_shake - Sold_shake << " remain available." << endl;
                break;
            }
        case 6:
        cout << "Enter number of chicken requested" << endl;
            cin >> quant;
            if (Quantitiy_chicken - Sold_chicken >= quant)
            {
                Sold_chicken = Sold_chicken + quant;
                Price_chicken = Price_chicken + quant* 15;
                cout << quant << " chicken have been alloted " << endl;
                break;
            }
            else
            {
                cout<< "Only " << Quantitiy_chicken - Sold_chicken << " remain available." << endl;
                break;
            }
        case 7:
            
            cout << "Sales Info" << endl;
            cout << "Quantity \t Sold \t Total Price" << endl;
            cout << "Rooms: " << Quantitiy_room << "\t" << Sold_room << "\t" << Price_room << endl;
            cout << "Pasta: " << Quantitiy_pasta << "\t" << Sold_pasta << "\t" << Price_pasta << endl;
            cout << "Burger: " << Quantitiy_burger << "\t" << Sold_burger << "\t" << Price_burger << endl;
            cout << "Noodles: " << Quantitiy_noodles << "\t" << Sold_noodles << "\t" << Price_noodles << endl;
            cout << "Shakes: " << Quantitiy_shake << "\t" << Sold_shake << "\t" << Price_shake << endl;
            cout << "Chicken: " << Quantitiy_chicken << "\t" << Sold_chicken << "\t" << Price_chicken << endl;
            cout<< endl << "Total: " << Price_burger + Price_chicken + Price_noodles + Price_pasta + Price_room + Price_shake;
            break;
            
        case 8:
            exit(0);
        default:
            cout<<"Select number from list" << endl;
            break;

    }
    goto m;


}