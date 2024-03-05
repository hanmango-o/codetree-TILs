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

int CustomBound(int left, int right, int target) {
    int mid = 0, ret = -1;
    while(left <= right) {
        mid = (left + right) / 2;
        if(arr[mid] <= target) {
            left = mid + 1;
            ret = max(ret, mid);
        } else {
            right = mid - 1;
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
        int x, y;
        cin >> x >> y;
        int tempX = CustomBound(0, N - 1, x);
        int tempY = CustomBound(0, N - 1, y);
        bool flagX = arr[tempX] == x;
        bool flagY = arr[tempY] == y;
        int answer = tempY - tempX;
        if(flagX || flagY) answer++;
        cout << answer << "\n";
    }
    return 0;
}