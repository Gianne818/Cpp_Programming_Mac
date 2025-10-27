#include <iostream>
using namespace std;

void displayHeader();
void displayJanuary();

int main (){
    displayHeader();
    int choice;
    char again;
    do{
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){ //display months according to choices
            case 1: displayJanuary(); break; 
            default: cout << "Invalid Entry!" << endl;
        }
        while(true){
            cout << "Again? Y/N?: ";
            cin >> again;
            again = tolower(again);
            if(again!='y' && again !='n'){
                cout << "Invalid Entry!" << endl;;
            }
            if(again=='n' || again == 'y'){
                break;
            }
        }

        if(again == 'n'){
            break;
        }
    } while(again!='n');
    

}

void displayHeader(){
    cout << "2025 Calendar\n";
    cout << "Programmer: Charlone Gianne V. Cruz\n";
    cout << "Date Finished: October 26, 2025\n";
    cout << "Main Menu\n";
    cout << char(218); //top-left corner
    for (int i = 0; i<36; i++){
        if(i==13){
            cout << char(191); //T-junction up
        } else if (i==23){
            cout << char(191);
        } else {
            cout << char(196); //Horizontal line
        }
       
    }
    cout << char(191) << endl; //top-right corner

    cout << char(179); //vertical line
    cout << "1 January   ";
    cout << char(194);
    cout << "5 May    ";
    cout << char(194);
    cout << "9 September ";
    cout << char(180);
    cout << endl;

    cout << char(195); //T-junction left
    for (int i = 0; i<36; i++){
        if(i==13){
            cout << char(197); //cross
        } else if (i==23){
            cout << char(197);
        } else {
            cout << char(197);
        }
    }
    cout << char(180); //T-junction right
    cout << endl;
    cout << char(179);
    cout << "2 February  ";
    cout << char(179);
    cout << "6 June   ";
    cout << char(179);
    cout << "10 October  ";
    cout << char(180);
    cout << endl;

    cout << char(195); //T-junction left
    for (int i = 0; i<36; i++){
        if(i==13){
            cout << char(197); //cross
        } else if (i==23){
            cout << char(197);
        } else {
            cout << char(197);
        }
    }
    cout << char(180); //T-junction right
    cout << endl;
    cout << char(179);
    cout << "3 March     ";
    cout << char(179);
    cout << "7 July   ";
    cout << char(179);
    cout << "11 November ";
    cout << char(180);
    cout << endl;

    cout << char(195); //T-junction left
    for (int i = 0; i<36; i++){
        if(i==13){
            cout << char(197); //cross
        } else if (i==23){
            cout << char(197);
        } else {
            cout << char(197);
        }
    }
    cout << char(180); //T-junction right
    cout << endl;
    cout << char(179);
    cout << "4 April     ";
    cout << char(179);
    cout << "8 August ";
    cout << char(179);
    cout << "12 December ";
    cout << char(180);
    cout << endl;

    cout << char(192); //bottom-left corner
    for (int i = 0; i<35; i++){
        if(i==13){
            cout << char(193); //T-junction down
        } else if (i==23){
            cout << char(193);
        } else {
            cout << char(196); //Horizontal line
        }
       
    }
    cout << char(217) << endl; //bottom-right corner
}

void Standard_DisplayMonthRowColSeparator(){
    cout << char(195); //T-junction left
    for (int i = 0; i<=27; i++){
        if(i%4==0){
            cout << char(197); //cross
        } else {
            cout << char(196);
        }
    }
    cout << char(180); //T-junction right
    cout << endl;
}

void First_DisplayMonthRowColSeparator(){
    cout << char(218); //Top-left corner
    for (int i = 0; i<=27; i++){
        if(i%4==0 && i!=0){
            cout << char(194); //T-junction up
        } else {
            cout << char(196);
        }
    }
    cout << char(191); //top-right corner
    cout << endl;
}

void Last_DisplayMonthRowColSeparator(){
    cout << char(192); //Bottom-left corner
    for (int i = 0; i<=27; i++){
        if(i%4==0 && i!=0){
            cout << char(193); //T-junction down
        } else {
            cout << char(196);
        }
    }
    cout << char(217); //bottom-right corner
    cout << endl;
}

void displayDays(){
    cout << char(179) << " S " << char(179) << " M " << char(179) << " T " << char(179) << " W " << char(179) << " T " << 
    char(179) << " F " << char(179) << " S " << char(179);
    cout << endl;
}


void displayJanuary(){
    cout << "January 2025\n";
    First_DisplayMonthRowColSeparator();
    displayDays();
    Standard_DisplayMonthRowColSeparator();
    
    cout << char(179) << "   " << char(179) << "   " << char(179) << "   ";

    int ctr = 4;
    for (int i = 1; i<=31; i++){
        if(i < 10){
            cout << char(179) << " " << i << " ";
        } else {
            cout << char(179) << " " << i;
        }
        
        if(ctr%7==0){
            cout << char(180);
            cout << endl;
            Standard_DisplayMonthRowColSeparator();
        } 
        ctr++;
   }
   cout << char(179) << "   " << char(180) << endl;
   Last_DisplayMonthRowColSeparator();
   cout << endl;
}
--------------------------------------

// Main Menu
// -------------------------------------
// 0123456789012345678901234567890123456
//  1 January    5 May     9 September56 
//  2 February   6 June    10 October456
//  3 March      7 July    11 November56
//  4 April      8 August  12 December56

//  |_S_|_M_|_T_|_W_|_T_|_F_|_S_|
//  012345678901234567890123456789
//  | S   M   T   W   T   F   S |
