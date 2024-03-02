#include <iostream>

using namespace std;

int N, M, answer;
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
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if(Find(a) == Find(b)) {
            answer++;
            continue;
        }
        Union(a, b);
    }
    int target = parent[1];
    for(int i = 2; i <= N; i++) {
        if(parent[i] == target) continue;
        answer++;
        target = parent[i];
    }
    cout << answer;

    return 0;
}