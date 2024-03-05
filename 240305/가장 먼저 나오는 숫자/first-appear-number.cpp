#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[100000];

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
        int x;
        cin >> x;
        int temp = LowerBound(0, N - 1, x);
        if(arr[temp] == x) cout << temp + 1;
        else cout << -1;
        cout << "\n";
    }
    return 0;
}