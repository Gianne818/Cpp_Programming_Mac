#include <iostream>
#include <fstream>
using namespace std;


//The fstream library contains the following classes
//ofstream - create and write files
//ifstream - reads from files
//fstream - creates, reads, and writes to files

int main (){
    //creating a file
    ofstream helloFile("hello.txt");
    helloFile << "Hello, World!";
    helloFile.close();

    //reading from file
    string helloText;
    ifstream hellofile("hello.txt");
    while (getline(hellofile, helloText)){
        cout << helloText << endl;
    }
    hellofile.close();

    //using fstream
    //ios::out - write mode; ios::in - read mode; ios::app - append mode
    string hellotext;
    fstream HelloFile; //You can also use .open
    HelloFile.open("hello.txt", ios::app | ios::in);
    HelloFile << endl << "I am a text file!";
    HelloFile.seekg(0); //if you dont want to use this func, close the file and reopen with ios::in
    //use .seekg to move the cursor, since using append will put cursor at the end of the file

    /* HelloFile.close();
    HelloFile.open("hello.txt", ios::in); */

    while (getline(HelloFile, hellotext)){
        cout << hellotext << endl;
    }

    HelloFile.close();
}