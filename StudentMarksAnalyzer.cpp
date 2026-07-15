#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of students.";
        return 0;
    }

    vector<int> marks(n);
    int sum = 0;

    cout << "Enter marks of students:\n";

    for (int i = 0; i < n; i++) {
        cin >> marks[i];
        sum += marks[i];
    }

    sort(marks.begin(), marks.end(), greater<int>());

    double average = static_cast<double>(sum) / n;

    cout << "\n--- Student Marks Analysis ---\n";
    cout << "Top 3 Marks:\n";

    int limit = min(3, n);

    for (int i = 0; i < limit; i++) {
        cout << i + 1 << ". " << marks[i] << endl;
    }

    cout << fixed << setprecision(2);
    cout << "Average Score: " << average << endl;

    return 0;
}
