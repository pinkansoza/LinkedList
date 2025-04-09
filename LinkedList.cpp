#include <iostream>

using namespace std;

struct MakananFavorit{
    string makanan;
    string rating;

    MakananFavorit *next;
};

MakananFavorit *head, *tail, *idx, *tambah, *hapus, *sebelum;

void buatList(string makanan, string rating){
    head = new MakananFavorit;
    head->makanan = makanan;
    head->rating = rating;
    head->next = NULL;
    tail = head;
}

void tambahAwal(string makanan, string rating){
    tambah = new MakananFavorit;
    tambah->makanan = makanan;
    tambah->rating = rating;
    tambah->next = head;
    head = tambah;
}

void tambahAkhir(string makanan, string rating){
    tambah = new MakananFavorit;
    tambah->makanan = makanan;
    tambah->rating = rating;
    tambah->next = NULL;
    tail->next = tambah;
    tail = tambah;
}

void tambahTertentu(string makanan, string rating, int posisi){
    tambah = new MakananFavorit;
    tambah->makanan = makanan;
    tambah->rating = rating;
    
    idx = head; 
    int cek = 1;
    while(cek < posisi-1){ 
        idx = idx->next;
        cek++;
    }

    tambah->next = idx->next;
    idx->next = tambah;
}
//untuk mengambil infotrmasi posisi satu sebelum target dan memeodifikasisanya untuk target 
void hapusAwal(){
    hapus = head; //pointer hapus menunjuk pointer hapus ke node pertama
    head = head->next; //memindahkan pointer head ke node berikutnya
    delete hapus;
}

void hapusAkhir(){
    hapus = tail;
    idx = head;
    while (idx->next != tail){
        idx = idx->next;
    }
    tail = idx; //Memperbarui pointer tail untuk menunjuk ke node yang sekarang ditunjuk oleh idx.
    tail->next = NULL; //Mengatur pointer next dari node yang sekarang ditunjuk oleh tail menjadi NULL.
    delete hapus;
}

void hapusTertentu(int posisi){
    idx = head;
    int cek = 1;
    while(cek <= posisi){
        if(cek == posisi -1){
            sebelum = idx;
        }
        if(cek == posisi){
            hapus = idx;
        }
        idx = idx->next;
        cek++;
    }
    sebelum->next = idx; //Menghubungkan node sebelum node yang dihapus ke node setelah node yang dihapus (idx)
    delete hapus; 
}

void printList(){
    idx = head;
    while(idx != NULL){
        cout << "Nama makanan: "<< idx->makanan << endl;
        cout << "Rating: "<< idx->rating << endl;
        idx = idx->next;
    }
}

int main(){

    buatList("mie ayam", "mabar!!!");
    printList();
    
    cout << "\n\n";

    tambahAwal("seblak", "hama");
    printList();

    cout << "\n\n";

    tambahAkhir("Sego Goreng", "mid");
    printList();

    cout << "\n\n";

    tambahTertentu("Bubur Ayam", "login", 3);
    printList();

    cout << "\n\n";

    hapusAwal();
    printList();

    cout << "\n\n";

    hapusAkhir();
    printList();

    cout << "\n\n";

    hapusTertentu(2);
    printList();
}