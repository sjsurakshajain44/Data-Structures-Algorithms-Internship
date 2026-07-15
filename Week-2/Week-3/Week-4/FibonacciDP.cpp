#include <iostream>
#include <vector>
using namespace std;

long long fibonacciMemo(int n, vector<long long>& dp) {
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibonacciMemo(n - 1, dp)
                 + fibonacciMemo(n - 2, dp);
}

long long fibonacciTabulation(int n) {
    if (n <= 1)
        return n;

    vector<long long> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    vector<long long> dp(n + 1, -1);

    cout << "Fibonacci using Memoization: "
         << fibonacciMemo(n, dp) << endl;

    cout << "Fibonacci using Tabulation: "
         << fibonacciTabulation(n) << endl;

    return 0;
}
