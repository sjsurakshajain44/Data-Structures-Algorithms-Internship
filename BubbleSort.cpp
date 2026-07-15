#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }

    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nTotal Swaps: " << swaps;

    return 0;
}
