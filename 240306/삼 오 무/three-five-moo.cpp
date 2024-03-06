#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int N;

long long getCnt(long long n) {
    return n - (n / 3 + n / 5 - n / 15);
}

long long BS(long long left, long long right) {
    long long mid = 0;
    while(left <= right) {
        mid = (left + right) / 2;
        if(getCnt(mid) == N) return mid;
        else if(getCnt(mid) < N) left = mid + 1;
        else right = mid - 1;
    }
    return mid;
}

int main() {
    cin >> N;
    cout << BS(1, INT_MAX);
    return 0;
}