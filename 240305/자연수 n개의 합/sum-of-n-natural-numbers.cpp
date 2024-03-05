#include <iostream>
#include <unordered_map>

using namespace std;

long long S;
unordered_map<long long, long long> um;

long long getSum(long long n, long long before) {
    long long sum = 0, temp = 0;
    if(um.find(before)!=um.end()) temp = um[before];
    if(n < before) {
        for(long long i = n + 1; i <= before; i++) {
            sum -= i;
        }
    } else {
        for(long long i = before + 1; i <= n; i++) {
            sum += i;
        }
    }
    
    return sum + temp;
}

long long BS(long long left, long long right) {
    long long mid = 0;
    long long before = 0;
    while(left <= right) {
        mid = (left + right) / 2;
        long long sum = getSum(mid, before);
        if(sum == S) return mid;
        else if(sum < S) left = mid + 1;
        else right = mid - 1;
        um.insert({mid, sum});
        before = mid;
    }
    return mid - 1;
}

int main() {
    cin >> S;
    cout << BS(1, S);
    return 0;
}