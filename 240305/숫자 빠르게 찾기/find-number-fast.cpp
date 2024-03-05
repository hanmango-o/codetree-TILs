#include <iostream>

using namespace std;

int N, M;
int arr[100000];

int BS(int left, int right, int target) {
    int mid = 0;
    while(left <= right) {
        mid = (left + right) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -2;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < M; i++) {
        int num;
        cin >> num;
        cout << BS(0, N - 1, num) + 1 << "\n";
    }
    return 0;
}