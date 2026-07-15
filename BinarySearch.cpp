#include <iostream>
using namespace std;

int main() {
    int n, key;

    cout << "Enter size of sorted array: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            cout << "Element found at index " << mid;
            return 0;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << "Element not found";

    return 0;
}
