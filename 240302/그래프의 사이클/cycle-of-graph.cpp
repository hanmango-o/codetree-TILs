#include <iostream>
#include <vector>

using namespace std;

int N, M;
int parent[100001];

int Find(int tar) {
    if(tar == parent[tar]) return tar;
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
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if(Find(a) == Find(b)) {
            cout << i + 1;
            return 0;
        }
        Union(a, b);
    }
    cout << "happy";
    return 0;
}