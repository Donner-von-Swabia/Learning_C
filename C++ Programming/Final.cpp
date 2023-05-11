#include <iostream>
#include <stdlib.h>
#include <string>
#include "final.h"
using namespace std;
class Guest{
    public:
        string Guest_Name;
        int Party_Size;
        bool Is_Special_Request;
        string Special_Request;
};

class Server{
    string Server_Name;
    int Num_of_tables;

};
Guest Guest1;
Guest Guest2;
Guest Guest3;
Guest Guest4;
Guest Guest5;


int tables[72] = {
    111,112,113,0,211,212,213,214,0,311,312,313,
    121,122,123,0,221,222,223,224,0,321,322,323,
    131,132,133,0,231,232,233,234,0,331,332,333,
    141,142,143,0,241,242,243,244,0,341,342,343,
    151,152,153,0,251,252,253,254,0,351,352,353,
    161,0,162,0,0,0,0,0,0,361,0,362};
int Cap[72] ={
    4,4,4,0,6,4,4,4,0,6,4,4,
    4,4,4,0,4,6,2,4,0,4,4,4,
    4,4,4,0,4,6,2,4,0,4,4,4,
    4,4,4,0,4,6,2,4,0,4,4,4,
    4,4,4,0,4,6,2,4,0,4,4,4,
    4,0,8,0,0,0,0,0,0,4,0,6};
int stat[72];
int opt = 1;
void mid_line_draw()
{
    int loader = 0;
    for (int i=0; i<6; i++)
    {
        for(int k=0; k<12;k++)
        {
            if(Cap[loader] == 0){
                cout <<"\033[0m" <<"|     " ;
            }
            else{
                if (stat[loader] == 1){
                    cout <<"\033[30;44m" << "|  " << Cap[loader] << "  " ;
                }
                else if(stat[loader] == 2){
                    cout <<"\033[30;43m" << "|  " << Cap[loader] << "  " ;
                }
                else{
                    cout <<"\033[30;42m" << "|  " << Cap[loader] << "  " ;
                }
            }
            loader++;
            
        }
        cout <<"|" <<"\033[0m" ;
        cout << endl;
        loader = loader - 12;
        for (int j=0;j<12;j++)
        {
            if(tables[loader]==0){
                cout <<"\033[0m" <<"|     " ;
            }
            else{
                if (stat[loader] == 1){
                    cout <<"\033[30;44m" << "| " << tables[loader] << " " ;
                }
                else if (stat[loader]==2){
                    cout <<"\033[30;43m" << "| " << tables[loader] << " " ;
                }
                else{
                    cout <<"\033[30;42m" << "| " << tables[loader] << " " ;
                }
            }
            loader++;
            
        }
        cout <<"|" <<"\033[0m" ;
        cout << endl;
        loader = loader - 12;
        for (int j=0;j<12;j++)
        {
            if(tables[loader]==0){
                cout <<"\033[0m" << "\033[4m" <<"|     " ;
            }
            else{
                if (stat[loader] == 1){
                    cout <<"\033[30;44m" << "|     " ;
                }
                else if(stat[loader]==2){
                    cout <<"\033[30;43m" << "|     " ;
                }
                else{
                    cout <<"\033[30;42m" << "|     " ;
                }
            }
            loader++;
            
        }
        cout <<"|" <<"\033[0m" ;
        cout << endl;
    }
}

int options(){
    if (opt == 1){
        cout<< "\t\t Welcome to the Seating Management System" << endl;
    }
    cout << "\t\t Please Select an option from the Menu" << endl;
    cout <<"1:Seat a party\t 2: Mark or Clear\t 3: Add party to wait\t 4: Wait List" << endl;
    cout <<"5: Edit Tables\t 6: Guide\t 7: Exit Program" << endl;
    int mode;
    cin >> mode;
    return mode;
}

int findnum(int num)
{
    for (int i=0;i<72;i++)
    {
        if (tables[i] == num){
            return i;
        }
        
    }
    return 100;
}
int findclear( int true_num){
    if (stat[true_num] == 1){
        return 1;
    }
    else{
        return 0;
    }
    
}
int clear_part(){
    cout << "Select Table : ";
    int num;
    cin >> num;
    int true_num, true_seat;
    true_num = findnum(num);
    if (true_num == 100){
        clear_part();
    }
    return true_num;    
}

int seat_part(){
    cout << "Select Table : ";
    int num;
    cin >> num;
    int true_num, true_seat;
    true_num = findnum(num);
    if (true_num == 100){
        seat_part();
    }
    true_seat = findclear(true_num);
    if (true_seat == 1){
        cout << "Table is not available" << endl;
        seat_part();
    }
    return true_num;    
}


void redraw(){
    top_line_draw();
    mid_line_draw();
}
void seat(int index){
    stat[index] = 1;
    clear_screen();
    redraw();
}
void find_cap(int capp){
    int num, opt;
    cout << "Enter the number of guest" ;
    cin >> num;
    if (num>capp){
        cout <<"The table can only hold " << capp << endl;
        cout <<" Options " << endl << "1: Continue \t 2: Seat less people\t 3: Select different table" << endl;
        cin >> opt;
        switch(opt){
            case 1:
                break;
            case 2:
                find_cap(capp);
                break;
            case 3:
                int index, seat_cap;
                index = seat_part();
                seat_cap = Cap[index];
                find_cap(seat_cap);
                seat(index);
                break;
        }
    }
}
void clear(){
    clear_screen();
    int index;
    index = clear_part();
    stat[index] = 0;
}
void mark(){
    clear_screen();
    int index;
    index = clear_part();
    stat[index] = 2;
}
void markorclear(){
    clear_screen();
    cout << "Select if you want to clear or mark a table" << endl << "1: Clear Table\t 2: Mark Table Dirty" << endl;
    int op;
    cin >> op;
    if (op == 1){
        clear();
    }
    else{
        mark();
    }
}
void Waitlist(){
    clear_screen();
    cout << "Select Wait List slot" << endl;
    cout << "Slot 1:" <<endl << "Name: " << Guest1.Guest_Name << " Party Size: " << Guest1.Party_Size << endl;
    if (Guest1.Is_Special_Request == true){
        cout << "Notes: " << Guest1.Special_Request << endl;
    }
        cout << "Slot 2:" <<endl << "Name: " << Guest2.Guest_Name << " Party Size: " << Guest2.Party_Size << endl;
    if (Guest2.Is_Special_Request == true){
        cout << "Notes: " << Guest2.Special_Request << endl;
    }
        cout << "Slot 3:" <<endl << "Name: " << Guest3.Guest_Name << " Party Size: " << Guest3.Party_Size << endl;
    if (Guest3.Is_Special_Request == true){
        cout << "Notes: " << Guest3.Special_Request << endl;
    }
        cout << "Slot 4:" <<endl << "Name: " << Guest4.Guest_Name << " Party Size: " << Guest4.Party_Size << endl;
    if (Guest4.Is_Special_Request == true){
        cout << "Notes: " << Guest4.Special_Request << endl;
    }
        cout << "Slot 5:" <<endl << "Name: " << Guest5.Guest_Name << " Party Size: " << Guest5.Party_Size << endl;
    if (Guest5.Is_Special_Request == true){
        cout << "Notes: " << Guest5.Special_Request << endl;
    }
}
void Waitlists(){
    clear_screen();
    int num;
    cout << "Slot 1:" <<endl << "Name: " << Guest1.Guest_Name << " Party Size: " << Guest1.Party_Size << endl;
    if (Guest1.Is_Special_Request == true){
        cout << "Notes: " << Guest1.Special_Request << endl;
    }
        cout << "Slot 2:" <<endl << "Name: " << Guest2.Guest_Name << " Party Size: " << Guest2.Party_Size << endl;
    if (Guest2.Is_Special_Request == true){
        cout << "Notes: " << Guest2.Special_Request << endl;
    }
        cout << "Slot 3:" <<endl << "Name: " << Guest3.Guest_Name << " Party Size: " << Guest3.Party_Size << endl;
    if (Guest3.Is_Special_Request == true){
        cout << "Notes: " << Guest3.Special_Request << endl;
    }
        cout << "Slot 4:" <<endl << "Name: " << Guest4.Guest_Name << " Party Size: " << Guest4.Party_Size << endl;
    if (Guest4.Is_Special_Request == true){
        cout << "Notes: " << Guest4.Special_Request << endl;
    }
        cout << "Slot 5:" <<endl << "Name: " << Guest5.Guest_Name << " Party Size: " << Guest5.Party_Size << endl;
    if (Guest5.Is_Special_Request == true){
        cout << "Notes: " << Guest5.Special_Request << endl;
    }
    cout <<"Enter any num to return";
    cin >> num;
    clear_screen();
    redraw();

}
void Guest1_Edit(){
    cout << "Enter the name of the party :";
    cin >> Guest1.Guest_Name;
    cout << "Enter party size";
    cin >> Guest1.Party_Size;
    cout << "Is there a special request ? Y/N :";
    string sec;
    cin >> sec;
    if (sec == "Y"){
        Guest1.Is_Special_Request = true;
        cout << "Enter the request: ";
        cin >> Guest1.Special_Request;
    }
}
void Guest2_Edit(){
    cout << "Enter the name of the party :";
    cin >> Guest2.Guest_Name;
    cout << "Enter party size";
    cin >> Guest2.Party_Size;
    cout << "Is there a special request ? Y/N :";
    string sec;
    cin >> sec;
    if (sec == "Y"){
        Guest2.Is_Special_Request = true;
        cout << "Enter the request: ";
        cin >> Guest2.Special_Request;
    }
}
void Guest3_Edit(){
    cout << "Enter the name of the party :";
    cin >> Guest3.Guest_Name;
    cout << "Enter party size";
    cin >> Guest3.Party_Size;
    cout << "Is there a special request ? Y/N :";
    string sec;
    cin >> sec;
    if (sec == "Y"){
        Guest3.Is_Special_Request = true;
        cout << "Enter the request: ";
        cin >> Guest3.Special_Request;
    }
}
void Guest4_Edit(){
    cout << "Enter the name of the party :";
    cin >> Guest4.Guest_Name;
    cout << "Enter party size";
    cin >> Guest4.Party_Size;
    cout << "Is there a special request ? Y/N :";
    string sec;
    cin >> sec;
    if (sec == "Y"){
        Guest4.Is_Special_Request = true;
        cout << "Enter the request: ";
        cin >> Guest4.Special_Request;
    }
}
void Guest5_Edit(){
    cout << "Enter the name of the party :";
    cin >> Guest5.Guest_Name;
    cout << "Enter party size";
    cin >> Guest5.Party_Size;
    cout << "Is there a special request ? Y/N :";
    string sec;
    cin >> sec;
    if (sec == "Y"){
        Guest5.Is_Special_Request = true;
        cout << "Enter the request: ";
        cin >> Guest5.Special_Request;
    }
}
void commands(){
    int mode;
    bool condiction = true;
    while (condiction == true){
        mode = options();
        switch(mode){
            case 1:
                clear_screen();
                int seat_id, seat_cap;
                seat_id = seat_part();
                seat_cap = Cap[seat_id];
                find_cap(seat_cap);
                seat(seat_id);
                break;
            case 2:
                markorclear();
                redraw();
                break;
            case 3:
                Waitlist();
                int selector;
                cout << "Enter Slot: ";
                cin >> selector;
                switch(selector){
                    case 1:
                        Guest1_Edit();
                        break;
                    case 2:
                        Guest2_Edit();
                        break;
                    case 3:
                        Guest3_Edit();
                        break;
                    case 4:
                        Guest4_Edit();
                        break;
                    case 5:
                        Guest5_Edit();
                        break;
                }
                redraw();
                break;
            case 4:
                Waitlists();
                break;
            case 5:
                cout << "WIP";
                break;
            case 6:
                cout <<"WIP";
                break;
            case 7: 
                condiction = false;
                clear_screen();
                break;
        }
    }
}
main(){
    for (int i=0;i<72;i++){
        stat[i] = 0;
    }
    Guest1.Guest_Name = "Empty";
    Guest1.Party_Size = 0;
    Guest1.Is_Special_Request = false;
    Guest1.Special_Request = "N/A";
    Guest2.Guest_Name = "Empty";
    Guest2.Party_Size = 0;
    Guest2.Is_Special_Request = false;
    Guest2.Special_Request = "N/A";
    Guest3.Guest_Name = "Empty";
    Guest3.Party_Size = 0;
    Guest3.Is_Special_Request = false;
    Guest3.Special_Request = "N/A";
    Guest4.Guest_Name = "Empty";
    Guest4.Party_Size = 0;
    Guest4.Is_Special_Request = false;
    Guest4.Special_Request = "N/A";
    Guest5.Guest_Name = "Empty";
    Guest5.Party_Size = 0;
    Guest5.Is_Special_Request = false;
    Guest5.Special_Request = "N/A";

    top_line_draw();
    mid_line_draw();
    commands();
    return 0;
}

