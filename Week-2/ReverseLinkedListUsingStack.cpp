#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    stack<int> s;
    Node* temp = head;

    while (temp != nullptr) {
        s.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while (temp != nullptr) {
        temp->data = s.top();
        s.pop();
        temp = temp->next;
    }

    cout << "Reversed Linked List: ";

    temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
