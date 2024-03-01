#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int arrK[100000], parent[100001];

int Find(int tar) {
    if(parent[tar] == tar) return tar;
    int ret = Find(parent[tar]);
    parent[tar] = ret;
    return ret;
}

void Union(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);
    if(pa == pb) return;
    parent[pb] = pa;
}

int main() {
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }

    for(int i = 0; i < K; i++) {
        cin >> arrK[i];
    }

    int temp = Find(arrK[0]);
    for(int k : arrK) {
        if(temp == Find(k)) continue;
        cout << 0;
        return 0;
    }
    cout << 1;


    return 0;
}