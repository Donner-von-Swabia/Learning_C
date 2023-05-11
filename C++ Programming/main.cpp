#include <iostream>
#include <stdlib.h>
#include <string>


using namespace std;
int tables[72] = {
    111,112,113,0,211,212,213,214,0,311,312,313,
    121,122,123,0,221,222,223,224,0,321,322,323,
    131,132,133,0,231,232,233,234,0,331,332,333,
    141,142,143,0,241,242,243,244,0,341,342,343,
    151,152,153,0,251,252,253,254,0,351,352,353,
    161,0,162,0,0,0,0,0,0,361,0,362};
int cap[72] ={
    4,4,4,0,6,4,4,4,0,6,4,4,
    4,4,4,0,4,6,2,4,0,4,4,4,
    4,4,4,0,4,6,2,4,0,4,4,4,
    4,4,4,0,4,6,2,4,0,4,4,4,
    4,4,4,0,4,6,2,4,0,4,4,4,
    4,0,8,0,0,0,0,0,0,4,0,6};
int stat[72];
class Table{
    public:
        int Table_Number;
        int Seating_Capacity;
        int Seat_Occupied;
        bool Is_Sat;
        bool Is_Clean;
        
};

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



void mid_line_draw(int Cap[], int tables[])
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
                cout <<"\033[30;42m" << "|  " << Cap[loader] << "  " ;
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
                cout <<"\033[30;42m" << "| " << tables[loader] << " " ;
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
                cout <<"\033[30;42;4m" << "|     " ;
            }
            loader++;
            
        }
        cout <<"|" <<"\033[0m" ;
        cout << endl;
    }
}

void init(int tables[],int Cap[])
{
    top_line_draw();
    mid_line_draw(Cap, tables);
}
int options(int opt){
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
void redraw()
int findnum(int tables[], int num)
{
    for (int i=0;i<72;i++)
    {
        if (tables[i] == num){
            return i;
        }
        
    }
    return 100;
}
int findclear(int stat[], int true_num){
    if (stat[true_num] == 1){
        return 1;
    }
    else{
        return 0;
    }
    
}

int seat_part(int tables[],int stat[]){
    cout << "Select Table : ";
    int num;
    cin >> num;
    int true_num, true_seat, true_cap;
    true_num = findnum(tables, num);
    if (true_num == 100){
        seat_part(tables,stat);
    }
    true_seat = findclear(stat,true_num);
    if (true_seat == 1){
        cout << "Table is not available" << endl;
        seat_part(tables,stat);
    }
    return true_num;
    
}
void seat(int tables[], int stat[], int cap[],int index){
    stat[index] = 1;
    clear_screen();
    redraw(tables, stat, cap);
}
void find_cap(int cap, int tables[], int stat[], int cap[]){
    int num, opt;
    cout << "Enter the number of guest" ;
    cin >> num;
    if (num>cap){
        cout <<"The table can only hold " << cap << endl;
        cout <<" Options " << endl << "1: Continue \t 2: Seat less people\t 3: Select different table" << endl;
        cin >> opt;
        switch(opt){
            case 1:
                break;
            case 2:
                find_cap(cap,tables, stat);
                break;
            case 3:
                int seat_id, seat_number, seat_cap;
                seat_id = seat_part(tables,stat);
                seat_number = tables[seat_id];
                seat_cap = cap[seat_id];
                find_cap(seat_cap, tables, stat);
                seat(tables,stat,cap,seat_id);
        }
    }
}
void commands(int tables[], int cap[],int stat[]){
    int opt = 1;
    int mode;
    mode = options(opt);
    switch(mode){
        case 1:
            int seat_id, seat_number, seat_cap;
            seat_id = seat_part(tables,stat);
            seat_number = tables[seat_id];
            seat_cap = cap[seat_id];
            find_cap(seat_cap, tables, stat);
            seat(tables,stat,cap,seat_id);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7: 
            break;
    }
}
int main()
{
    int tables[72] = {
        111,112,113,0,211,212,213,214,0,311,312,313,
        121,122,123,0,221,222,223,224,0,321,322,323,
        131,132,133,0,231,232,233,234,0,331,332,333,
        141,142,143,0,241,242,243,244,0,341,342,343,
        151,152,153,0,251,252,253,254,0,351,352,353,
        161,0,162,0,0,0,0,0,0,361,0,362};
    int cap[72] ={
        4,4,4,0,6,4,4,4,0,6,4,4,
        4,4,4,0,4,6,2,4,0,4,4,4,
        4,4,4,0,4,6,2,4,0,4,4,4,
        4,4,4,0,4,6,2,4,0,4,4,4,
        4,4,4,0,4,6,2,4,0,4,4,4,
        4,0,8,0,0,0,0,0,0,4,0,6};
    int stat[72];
    for (int i=0;i<72;i++){
        stat[i] = 0;
    }
    stat[0] = 1;
    init(tables,cap);
    commands(tables,cap,stat);
    
    return 0;


}