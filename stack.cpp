#include <iostream>
using namespace std;

int maks = 4;
string arrayMinuman[4];
int top = 0;

bool isFull(){
    if(top == maks){
        return true;
    }else{
        return false; 
    }
}

void pushArray(string data){
    if(isFull()){
        cout << "Data Penuh" << endl;
    }else{
        arrayMinuman[top] = data;
        top++;
    }
}

void displayArray(){
    cout << "Data stack Array: " << endl;
    for(int i = maks-1; i >= 0; i--){
        if(arrayMinuman[i] !=""){
            cout << "Data: " << arrayMinuman[i] << endl;
            i--;
        }
    }
}

int main() {

    pushArray("Fanta");
    displayArray();
    pushArray("Sprite");
    displayArray();

    return 0;
}