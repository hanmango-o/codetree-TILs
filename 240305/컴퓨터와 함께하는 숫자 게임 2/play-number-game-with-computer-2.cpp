#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

long long M, A, B;
int MAX, MIN = INT_MAX;

int BS(long long left, long long right, long long target) {
    long long mid = 0;
    int cnt = 0;
    while (left <= right) {
        cnt++;
        mid = (left + right) / 2;
        if (mid == target) break;
        else if (mid < target) left = mid + 1;
        else right = mid - 1;
    }
    return cnt;
}

int main() {
    cin >> M >> A >> B;
    for (long long i = A; i <= B; i++) {
        int temp = BS(1, M, i);
        MAX = max(MAX, temp);
        MIN = min(MIN, temp);
    }
    cout << MIN << " " << MAX;
    return 0;
}