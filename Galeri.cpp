#include <iostream>
#include <string>
#include <limits>  // Diperlukan untuk numeric_limits
using namespace std;

// Fungsi untuk membersihkan layar terminal
void clearScreen() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

// Node untuk menyimpan satu gambar dalam gallery
typedef struct Node {
    string name;
    Node* prev;
    Node* next;
    
    // Konstruktor untuk menginisialisasi node baru
    Node(const string& _name)
        : name(_name), prev(nullptr), next(nullptr) {}
} Node;

// Doubly Linked List untuk Gallery
class Gallery {
private:
    Node* head;      // Pointer ke node pertama
    Node* current;   // Pointer ke node yang sedang dilihat

public:
    Gallery() : head(nullptr), current(nullptr) {}
    ~Gallery() {
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    void addImage(const string& name) {
        Node* node = new Node(name);
        if (!head) head = current = node;
        else {
            Node* tail = head;
            while (tail->next) tail = tail->next;
            tail->next = node;
            node->prev = tail;
        }
        cout << "Added: " << name << endl;
    }

    void showCurrent() const {
        if (current) cout << "Viewing: " << current->name << endl;
        else cout << "Gallery is empty." << endl;
    }

    void nextImage() {
        if (current && current->next) { current = current->next; showCurrent(); }
        else cout << "No next image." << endl;
    }

    void prevImage() {
        if (current && current->prev) { current = current->prev; showCurrent(); }
        else cout << "No previous image." << endl;
    }

    void deleteCurrent() {
        if (!current) { cout << "Gallery is empty." << endl; return; }
        cout << "Deleting: " << current->name << endl;
        Node* prevNode = current->prev;
        Node* nextNode = current->next;
        if (prevNode) prevNode->next = nextNode;
        else head = nextNode;
        if (nextNode) nextNode->prev = prevNode;
        delete current;
        current = nextNode ? nextNode : prevNode;
    }

    void showAll() const {
        if (!head) { cout << "Gallery is empty." << endl; return; }
        cout << "Gallery contents:" << endl;
        Node* temp = head;
        int idx = 1;
        while (temp) {
            cout << idx << ". " << temp->name;
            if (temp == current) cout << " <- current";
            cout << endl;
            temp = temp->next;
            idx++;
        }
    }
};

int main() {
    Gallery gallery;
    int choice;
    string input;
    string name;

    do {
        // Bersihkan layar setiap kali menampilkan menu baru
        clearScreen();

        cout << "\n--- Gallery Menu ---" << endl;
        cout << "1. Add Image" << endl;
        cout << "2. Show Current Image" << endl;
        cout << "3. Next Image" << endl;
        cout << "4. Previous Image" << endl;
        cout << "5. Delete Current Image" << endl;
        cout << "6. Show All Images" << endl;
        cout << "7. Exit" << endl;
        cout << "Choose (1-7): ";

        // Baca input sebagai string untuk validasi
        getline(cin, input);
        try { choice = stoi(input); }
        catch (...) { choice = -1; }

        switch (choice) {
            case 1:
                cout << "Enter image name/path: ";
                getline(cin, name);
                gallery.addImage(name);
                break;
            case 2:
                gallery.showCurrent();
                break;
            case 3:
                gallery.nextImage();
                break;
            case 4:
                gallery.prevImage();
                break;
            case 5:
                gallery.deleteCurrent();
                break;
            case 6:
                gallery.showAll();
                break;
            case 7:
                cout << "Exiting. Destructor will be called automatically, cleaning up memory." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

        // Tunggu input untuk melanjutkan agar output tetap terlihat
        if (choice != 7) {
            cout << "\nPress Enter to continue...";
            getline(cin, input);
        }
    } while (choice != 7);

    return 0;
}
