#include <iostream>

using namespace std;

int N;

int dp[1001];

int main() {
    cin >> N;
    dp[0] = dp[2] = dp[3] = 1;
    dp[1] = 0;
    for(int i = 4; i <= N; i++) {
        dp[i] = (dp[i - 2] + dp[i - 3]) % 10007;
    }
    cout << dp[N] % 10007;
    return 0;
}