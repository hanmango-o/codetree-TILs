#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int N;

long long getCnt(long long n) {
    return n - (n / 3 + n / 5 - n / 15);
}

long long BS(long long left, long long right) {
    long long mid = 0, ret = INT_MAX;
    while(left <= right) {
        mid = (left + right) / 2;
        if(getCnt(mid) < N) {
            left = mid + 1;
            ret = min(ret, mid);
        }
        // else if(getCnt(mid) < N) left = mid + 1;
        else right = mid - 1;
    }
    return mid;
}

int main() {
    cin >> N;
    long long temp = BS(1, INT_MAX);
    cout << (temp % 3 == 0 || temp % 5 == 0 ? temp + 1 : temp);
    return 0;
}