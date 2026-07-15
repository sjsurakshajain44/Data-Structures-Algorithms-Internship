#include <iostream>
using namespace std;

#define SIZE 10

class HashTable {
private:
    int table[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);

        while (table[index] != -1) {
            index = (index + 1) % SIZE;
        }

        table[index] = key;
    }

    void display() {
        cout << "Hash Table:\n";

        for (int i = 0; i < SIZE; i++) {
            cout << i << " -> ";

            if (table[i] == -1)
                cout << "Empty";
            else
                cout << table[i];

            cout << endl;
        }
    }
};

int main() {
    HashTable table;

    table.insert(10);
    table.insert(20);
    table.insert(25);
    table.insert(35);

    table.display();

    return 0;
}
