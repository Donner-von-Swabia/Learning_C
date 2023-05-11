#include <iostream>
#include <stdlib.h>
#include <string>
// Header file used to hold smaller void functions.
#include "final.h"
#include "Final_P2.h"
using namespace std;
// Class is used to allows guest to wait
class Guest{
    public:
        string Guest_Name;
        int Party_Size;
        bool Is_Special_Request;
        string Special_Request;
};
// Part of WIP was going to join another array that holds the each server for each table this filling in the bottom line in each cell
class Server{
    string Server_Name;
    int Num_of_tables;

};
// I have no idea how to procedually iterate class iterations thus I only used 5...
Guest Guest1;
Guest Guest2;
Guest Guest3;
Guest Guest4;
Guest Guest5;

// Array used to buld table
int tables[72] = {
    111,112,113,0,211,212,213,214,0,311,312,313,
    121,122,123,0,221,222,223,224,0,321,322,323,
    131,132,133,0,231,232,233,234,0,331,332,333,
    141,142,143,0,241,242,243,244,0,341,342,343,
    151,152,153,0,251,252,253,254,0,351,352,353,
    161,0,162,0,0,0,0,0,0,361,0,362};
// Array used to build table and maintain that the correct amount of people at seated at a specific table
int Cap[72] ={
    4,4,4,0,6,4,4,4,0,6,4,4,
    4,4,4,0,4,6,2,4,0,4,4,4,
    4,4,4,0,4,6,2,4,0,4,4,4,
    4,4,4,0,4,6,2,4,0,4,4,4,
    4,4,4,0,4,6,2,4,0,4,4,4,
    4,0,8,0,0,0,0,0,0,4,0,6};
// Array used for the status of each table, in main function all 72 values are set to 0 to initilize program
int stat[72];
// Used in the options functions to say welcome and changed later so that is does not appear each redraw
int opt = 1;
void mid_line_draw()
{// Likely the hardest working function
/*
This function is designed to produce this:
_________________________________________________________________________
|  4  |  4  |  4  |     |  6  |  4  |  4  |  4  |     |  6  |  4  |  4  |
| 111 | 112 | 113 |     | 211 | 212 | 213 | 214 |     | 311 | 312 | 313 |
|     |     |     |     |     |     |     |     |     |     |     |     |
|  4  |  4  |  4  |     |  4  |  6  |  2  |  4  |     |  4  |  4  |  4  |
| 121 | 122 | 123 |     | 221 | 222 | 223 | 224 |     | 321 | 322 | 323 |
|     |     |     |     |     |     |     |     |     |     |     |     |
|  4  |  4  |  4  |     |  4  |  6  |  2  |  4  |     |  4  |  4  |  4  |
| 131 | 132 | 133 |     | 231 | 232 | 233 | 234 |     | 331 | 332 | 333 |
|     |     |     |     |     |     |     |     |     |     |     |     |
|  4  |  4  |  4  |     |  4  |  6  |  2  |  4  |     |  4  |  4  |  4  |
| 141 | 142 | 143 |     | 241 | 242 | 243 | 244 |     | 341 | 342 | 343 |
|     |     |     |     |     |     |     |     |     |     |     |     |
|  4  |  4  |  4  |     |  4  |  6  |  2  |  4  |     |  4  |  4  |  4  |
| 151 | 152 | 153 |     | 251 | 252 | 253 | 254 |     | 351 | 352 | 353 |
|     |     |     |     |     |     |     |     |     |     |     |     |
|  4  |     |  8  |     |     |     |     |     |     |  4  |     |  6  |
| 161 |     | 162 |     |     |     |     |     |     | 361 |     | 362 |
|     |     |     |     |     |     |     |     |     |     |     |     |

with the ability to manipulate data within it.
To do this three arrays are used
Tables hold all the table names
Cap holds all the capacity numbers
stat holds the satus of each table

if there isn't a table, capacity, or status 0 is used since an array has to be made of integers.
the layout is to look like a table 12 by 6 with 5 x 3 cells
*/
    int loader = 0;
    // Used to count each cell
    for (int i=0; i<6; i++)
    // Used to get 6 rows
    {
        for(int k=0; k<12;k++)
        // draws the first line of 3 lines in each cells
        {
            if(Cap[loader] == 0){
            // First if struct here is for capacity
                // This is base case for no capacity
                cout <<"\033[0m" <<"|     " ;
            }
            else{
                if (stat[loader] == 1){
                    // checks if table is taken blue
                    cout <<"\033[30;44m" << "|  " << Cap[loader] << "  " ;
                }
                else if(stat[loader] == 2){
                    // checks if table is marked yellow
                    cout <<"\033[30;43m" << "|  " << Cap[loader] << "  " ;
                }
                else{
                    // if table is availiable then it is green
                    cout <<"\033[30;42m" << "|  " << Cap[loader] << "  " ;
                }
            }
            loader++;
            // Needed to iterate through loop and move to next element in array
            
        }
        // clean up code
        cout <<"|" <<"\033[0m" ;
        cout << endl;
        // Needed as loader has gone 12 but for capcaity only not table numbers
        loader = loader - 12;
        for (int j=0;j<12;j++)
        // Same as before but for table numbers
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
        // Same as before but the bottom line in the cell where there is no data besides 5 spaces.
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
        // Notice no loader=loader-12 as it needs to go to the next cell rather than repeating first row.
    }
}
int findnum(int num)
// Comparies the table array data to the number being selected then returns the id for use in finding the status of the table.
{
    for (int i=0;i<72;i++)
    {
        if (tables[i] == num){
            return i;
        }
        
    }
    return 100;
}
int findclear( int true_num)
{
    // Checks if table from past function is availiable or taken by checking the status of the table based on the status array with the table array id.
    if (stat[true_num] == 1){
        return 1;
    }
    else{
        return 0;
    }
    
}

int seat_part(){
    // Initial function of the Case 1: Seating: Allows user to select table and send it to a function to check if it is an actual table
    // Then checkes if the table is available, incase the table is already occupied.
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
int options(){
    // Part of the Commands functions supposed to be called everytime the main page is redrawn, called from commands.
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


int clear_part(){
    // Similar to Seat_part: Part of Case 2: Allows users to select table then calls function to check if it is an actual table
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

void redraw(){
    // Basic function that redraws the table layout: Allows for updates to occur.
    top_line_draw();
    mid_line_draw();
}
void seat(int index){
    // Final Function of Case 1: Seating : Function changes the status of the table, clears the screen, then calls redraws to update.
    stat[index] = 1;
    clear_screen();
    redraw();
}
void find_cap(int capp){
    // Function finds the capacity of a table and how many people the user wants to seat at a given time then comparies if its possible
    int num, opt;
    cout << "Enter the number of guest" ;
    cin >> num;
    if (num>capp){
        cout <<"The table can only hold " << capp << endl;
        cout <<" Options " << endl << "1: Continue \t 2: Seat less people\t 3: Select different table" << endl;
        cin >> opt;
        switch(opt){
            // Will for the user to either allow the difference, change the number of people, or change the table.
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
    //Clears the screen of prompts then changes the status array to 0 then returns to command function which redraws the floor plan.
    clear_screen();
    int index;
    index = clear_part();
    stat[index] = 0;
}
void mark(){
    //Clears screen of prompts then changes the status of the table then return to command and redraws the updated floor plan
    clear_screen();
    int index;
    index = clear_part();
    stat[index] = 2;
}
void markorclear(){
    // Case 2: Allows the user to select weather they want to mark table or clear it. Moves to Clear() or Mark() functions
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
    // Case 3: Display Slots then prompts user to select on then runs through the modify slot function depending on selection.
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
    // Case 4: Display Waitlist then promts the user to enter a number to return to the main page.
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
    // Modify the first guest slot
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
    // Modify the 2nd guest slot
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
    //Modify the 3rd guest slot
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
    // Modify the 4th guest slot
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
    // Modify the 5th guest slot
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
    // Main Function : Allows users to perform different operations
    int mode;
    bool condiction = true;
    while (condiction == true){
        // Allows for the operations to be selected multiple times.
        mode = options();
        opt = 0;
        switch(mode){
            case 1:
                // Seating
                clear_screen();
                int seat_id, seat_cap;
                seat_id = seat_part();
                seat_cap = Cap[seat_id];
                find_cap(seat_cap);
                seat(seat_id);
                break;
            case 2: 
                //Marking and Clearing
                markorclear();
                redraw();
                break;
            case 3:
                // Allows users to select waitlist slot and to add information
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
                // Displays waitlist
                Waitlists();
                break;
            case 5:
                cout << "WIP";
                break;
            case 6:
                cout <<"WIP";
                break;
            case 7: 
                // Exit the program
                condiction = false;
                clear_screen();
                break;
        }
    }
}
main(){
    // Initializes the status of each table to 0, which will be changed later
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

