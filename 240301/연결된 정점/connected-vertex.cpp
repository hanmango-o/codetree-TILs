#include <iostream>

using namespace std;

int N, M;
int parent[100001], DAT[100001];

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
    DAT[pa] += DAT[pb];
    DAT[pb] = 0;
}

int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
        DAT[i] = 1;
    }
    for(int i = 0; i < M; i++) {
        char cmd;
        cin >> cmd;
        if(cmd == 'x') {
            int a, b;
            cin >> a >> b;
            Union(a, b);
        } else {
            int a;
            cin >> a;
            int pa = Find(a);
            cout << DAT[pa] << "\n";
        }
    }
    return 0;
}