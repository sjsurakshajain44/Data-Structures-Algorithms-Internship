#include <iostream>
#include <string>
using namespace std;

class Contact {
public:
    string name;
    string phone;
    Contact* left;
    Contact* right;

    Contact(string n, string p) {
        name = n;
        phone = p;
        left = nullptr;
        right = nullptr;
    }
};

Contact* insert(Contact* root, string name, string phone) {
    if (root == nullptr)
        return new Contact(name, phone);

    if (name < root->name)
        root->left = insert(root->left, name, phone);
    else
        root->right = insert(root->right, name, phone);

    return root;
}

Contact* search(Contact* root, string name) {
    if (root == nullptr || root->name == name)
        return root;

    if (name < root->name)
        return search(root->left, name);

    return search(root->right, name);
}

Contact* findMin(Contact* root) {
    while (root->left != nullptr)
        root = root->left;

    return root;
}

Contact* deleteContact(Contact* root, string name) {
    if (root == nullptr)
        return root;

    if (name < root->name)
        root->left = deleteContact(root->left, name);
    else if (name > root->name)
        root->right = deleteContact(root->right, name);
    else {
        if (root->left == nullptr) {
            Contact* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == nullptr) {
            Contact* temp = root->left;
            delete root;
            return temp;
        }

        Contact* temp = findMin(root->right);
        root->name = temp->name;
        root->phone = temp->phone;

        root->right =
            deleteContact(root->right, temp->name);
    }

    return root;
}

void displayContacts(Contact* root) {
    if (root == nullptr)
        return;

    displayContacts(root->left);
    cout << root->name << " - " << root->phone << endl;
    displayContacts(root->right);
}

int main() {
    Contact* root = nullptr;

    root = insert(root, "Suraksha", "9876543210");
    root = insert(root, "Aman", "9876501234");
    root = insert(root, "Riya", "9123456780");

    cout << "Contact Directory:\n";
    displayContacts(root);

    string name;
    cout << "\nEnter contact name to search: ";
    cin >> name;

    Contact* result = search(root, name);

    if (result != nullptr)
        cout << "Contact Found: "
             << result->name << " - "
             << result->phone << endl;
    else
        cout << "Contact not found\n";

    root = deleteContact(root, "Aman");

    cout << "\nAfter deleting Aman:\n";
    displayContacts(root);

    return 0;
}
