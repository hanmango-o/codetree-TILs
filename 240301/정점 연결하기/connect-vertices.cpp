#include <iostream>

using namespace std;

int N;
int parent[100001];

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
    cin >> N;

    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }
    int before = 1;
    for(int i = 2; i <= N; i++) {
        int pnow = parent[i];
        if(pnow != parent[before]) {
            cout << parent[before] << " " << pnow;
            return 0;
        }
        before = i;
    }

    return 0;
}