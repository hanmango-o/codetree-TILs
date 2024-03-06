#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, M, MIN = INT_MAX;
int arr[10000];

int getCnt(int n) {
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cnt += (arr[i] / n);
    }
    return cnt;
}

int UpperBound(int left, int right) {
    int mid = 0, ret = -1;
    while(left <= right) {
        mid = (left + right) / 2;
        // cout << mid << " ";
        if(getCnt(mid) >= M) {
            // cout << "1\n";
            left = mid + 1;
            ret = max(ret, mid);
        } else {
            // cout << "2\n";
            right = mid - 1;
        }
    }
    return ret;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        if(MIN > arr[i]) MIN = arr[i];
    }
    cout << UpperBound(1, MIN);


    return 0;
}