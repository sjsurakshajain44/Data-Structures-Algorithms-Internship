#include <iostream>
using namespace std;

#define SIZE 10

class HashMap {
private:
    int keys[SIZE];
    int values[SIZE];
    bool occupied[SIZE];

public:
    HashMap() {
        for (int i = 0; i < SIZE; i++)
            occupied[i] = false;
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int key, int value) {
        int index = hashFunction(key);

        while (occupied[index]) {
            index = (index + 1) % SIZE;
        }

        keys[index] = key;
        values[index] = value;
        occupied[index] = true;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            if (occupied[i])
                cout << i << " -> " << keys[i]
                     << " : " << values[i] << endl;
            else
                cout << i << " -> Empty" << endl;
        }
    }
};

int main() {
    HashMap map;

    map.insert(1, 100);
    map.insert(11, 200);
    map.insert(21, 300);

    map.display();

    return 0;
}
