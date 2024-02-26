#include <iostream>

using namespace std;

int N;
int dp[46];
int memo[46];

int Fibo(int n) {
    if(n <= 2) return 1;
    if(memo[n] > 0) return memo[n];
    return Fibo(n - 1) + Fibo(n - 2);
}

int main() {
     cin >> N;
     cout << Fibo(N);
    return 0;
}