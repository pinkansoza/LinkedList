#include <iostream>
using namespace std;

// deklarasi double linked list
struct DataUser{
  string nama;
  DataUser *prev;
  DataUser *next;
};

DataUser *head, *tail, *cur, *newNode, *del, *afterNode;

// Create Double Linked List
void createDoubleLinkedList( string nama ){
  head = new DataUser();
  head->nama = nama;
  
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

// Add First
void addFirst( string nama ){
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    newNode = new DataUser();
    newNode->nama = nama;
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

// Add Last
void addLast( string nama ){
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    newNode = new DataUser();
    newNode->nama = nama;
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
  }
}

// Add Middle
void addMiddle( string nama, int posisi ){
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
      newNode = new DataUser();
      newNode->nama = nama;

      // transversing
      cur = head;
      int nomor = 1;
      while( nomor <  posisi - 1){
        cur = cur->next;
        nomor++;
      }

      afterNode = cur->next;
      newNode->prev = cur;
      newNode->next = afterNode;
      cur->next = newNode;
      afterNode->prev = newNode;
  }
}

// remove First
void removeFirst()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    del = head;
    head = head->next;
    head->prev = NULL;
    delete del;
  }
}

// remove Last
void removeLast()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
  }
}

// remove Middle
void removeMiddle(int posisi){
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
      int nomor = 1;
      cur = head;
      while( nomor < posisi - 1 ){
        cur = cur->next;
        nomor++;
      }
      del = cur->next;
      afterNode = del->next;
      cur->next = afterNode;
      afterNode->prev = cur;
      delete del;
  }
}

// Print Double Linked List
void printDoubleLinkedList()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    cout << "Isi Data : " << endl;
    cur = head;
    while( cur != NULL ){
      // print
      cout << "Nama User : " << cur->nama << endl;
      // step
      cur = cur->next;
    }
  }
  cout << endl;
}

int main(){

  createDoubleLinkedList("Budi");

  printDoubleLinkedList();

  addFirst( "Speed" );

  printDoubleLinkedList();

  addLast("Wagon");

  printDoubleLinkedList();

  addMiddle("Abizar", 3);

  printDoubleLinkedList();

  removeMiddle(2);

  printDoubleLinkedList();


}