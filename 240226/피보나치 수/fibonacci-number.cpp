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
     dp[1] = 1;
     dp[2] = 1;
     cin >> N;
     for(int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
     }
     cout << dp[N];
    return 0;
}