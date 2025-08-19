#include <iostream>
using namespace std;

int main (){
    int r, c;
    cout << "Enter the number of rows and columns: ";
    cin >> r;
    cin >> c;
    
    int arr[r][c];
    
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            cin >> arr[i][j];
        }
    }
    
    cout << "Original Matrix:\n";
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "Rotated Matrix:\n";
    for (int i = 0; i<c; i++){
        for (int j = 0; j<r; j++){
            cout << arr[r-1-j][i] << " ";
        }
        cout << endl;
    }
    
}