#include <iostream>

using namespace std;

int N;
int dp[46];
int memo[46];

int Fibo(int n) {
    if(memo[n] != 0) return memo[n];

    if(n <= 2) return 1;

    int a = Fibo(n - 1);
    int b = Fibo(n - 2);

    memo[n] = a + b;
    return a + b;
}

int main() {
     cin >> N;
     cout << Fibo(N);
    return 0;
}