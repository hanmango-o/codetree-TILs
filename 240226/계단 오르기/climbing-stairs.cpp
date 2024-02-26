#include <iostream>

using namespace std;

int memo[1001];

int DP(int n) {
    if(n < 0) return 0;
    if(n == 2 || n == 3) return 1;
    if(memo[n] != 0) return memo[n];
    int a = DP(n - 2);
    int b = DP(n - 3);
    memo[n] += a + b;
    return a + b;
}

int N;

int main() {
    cin >> N;
    cout << DP(N) % 10007;
    return 0;
}