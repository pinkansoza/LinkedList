#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void beginInsert(Node** head, int nodeData) {
    Node* newNode = new Node(); // membuat node baru

    newNode->data = nodeData; // mengisi data node baru
    newNode->next = *head; // menghubungkan node baru dengan node sebelumnya

    *head = newNode; // memperbarui head dengan node baru

    cout << "Begin Insert Succesfully" << endl;
} // Node baru akan berada di depan linked list setiap kali beginInsert dipanggil.

void printLinkedList(Node* head) {
    cout << "Linked List Contents: ";
    while (head != NULL) {
        cout << head->data << " "; //Menampilkan data setiap node hingga mencapai node terakhir (nullptr).
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL; // inisialisasi linked list kosong

    // menambahkan elemen ke linked list
    beginInsert(&head, 10);
    beginInsert(&head, 5);

    // menampilkan isi linked list
    printLinkedList(head);

    return 0;
}