#include <iostream>
using namespace std;

//recursion
int revNum(int n){
    static int temp = n;
    static int res = 0;
    if(n==0) return res;
    temp=n%10;
    res = res*10+temp;
    return revNum(n/=10);
}

int main (){
    int n;
    cout << "Enter number: ";
    cin >> n;

    int res = 0;
    for (int i = n; i>0; i/=10){
        int temp = i%10;
        res = res*10 + temp;
    }

    cout << "Reversed: " << revNum(n);


}