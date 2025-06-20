#include <iostream>
using namespace std;

int main (){
    bool ships [5][5] = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1}
    };
    int x, y;
    int turns = 15, numShips = 9;
    cout << "You have 15 turns to eliminate 9 ships in a sea of 5 by 5. Enter a coordinate to eliminate." << endl;
    while (turns!=0){
        cout << "Enter x: ";
        cin >> x;
        while(x>=5||x<0){
            cout << "Invalid Coordinates!\n";
            cout << "Enter x: ";
            cin >> x;
        }
        cout << "Enter y: ";
        cin >> y;
        while(y>5||y<0){
            cout << "Invalid Coordinates!\n";
            cout << "Enter y: ";
            cin >> y;
        }
       
        
        turns--;
        

        if(ships[x][y]){
            numShips--;
            ships[x][y]=0;
            cout << "You have succesfully eliminated a ship." << endl; 
            cout << "Turns left: " << turns << endl;
            cout << "Ships left: " << numShips << endl <<  endl;
        } else {
            cout << "There was no ship in the spot you chose." << endl; 
            cout << "Turns left: " << turns << endl;
            cout << "Ships left: " << numShips << endl << endl;
        }

        if(numShips==0 || turns < numShips) break;
    }
    
    if((turns==0 || turns < numShips) && numShips !=0){
        cout << "You lost!";
    } else {
        cout << "You win!";
    }

}