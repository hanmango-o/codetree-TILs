#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[100];

int UpperBound(int left, int right, int target) {
    int mid = 0, ret = N;
    while(left <= right) {
        mid = (left + right) / 2;
        if(arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
            ret = min(ret, mid);
        }
    }
    return ret;
}

int LowerBound(int left, int right, int target) {
    int mid = 0, ret = N;
    while(left <= right) {
        mid = (left + right) / 2;
        if(arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
            ret = min(ret, mid);
        }
    }
    return ret;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < M; i++) {
        int num;
        cin >> num;
        cout << UpperBound(0, N - 1, num) - LowerBound(0, N - 1, num) << "\n";
    }
    return 0;
}