#include <iostream>
#include <unordered_map>

using namespace std;

long long S;

long long getSum(long long n) {
    return n * (1 + n) / 2;
}

long long BS(long long left, long long right) {
    long long mid = 0;
    while(left <= right) {
        mid = (left + right) / 2;
        long long sum = getSum(mid);
        if(sum == S) return mid;
        else if(sum < S) left = mid + 1;
        else right = mid - 1;
    }
    return mid - 1;
}

int main() {
    cin >> S;
    cout << BS(1, S);
    return 0;
}