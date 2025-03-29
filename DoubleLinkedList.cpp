#include <iostream>

using namespace std;

struct node{
    string nama;

    node *next;
    node* prev;
};

int main(){
    //membuat node
    node *node1, *node2;
    node1 = new node;
    node2 = new node;
    
    //Mengisi node1
    node1->nama = "Budi";
        //menyambungkan node1
    node1->next = node2;
    node1->prev = NULL; //NULL menunjukkan bahwa node1 sebagai head

    //Mengisi node2
    node2->nama = "Speed";
        //menyambungkan node2
    node2->next = NULL; //NULL menunjukkan bahwa node2 sebagai tail
    node2->prev = node1;

    //Membuat keluaran dari tail menuju head
    node *cur;
    cur = node2;
    while(cur != NULL){
        cout << "Nama:" << cur->nama << endl;
        cur=cur->prev;
    }
}