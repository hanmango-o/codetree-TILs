#include <iostream>
#include <algorithm>

using namespace std;

long long S;

long long CustomBound(int left, int right) {
    long long mid = 0, ret = 0, sum;
    while(left <= right) {
        mid = (left + right) / 2;
        sum = mid * (mid + 1) / 2;
        if(sum <= S) {
            left = mid + 1;
            ret = max(ret, mid);
        } else {
            right = mid - 1;
        }
    }
    return ret;
}

int main() {
    cin >> S;
    cout << CustomBound(0, 2000000000);

    return 0;
}