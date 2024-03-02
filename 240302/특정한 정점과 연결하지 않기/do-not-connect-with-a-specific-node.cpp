#include <iostream>

using namespace std;

int N, M, A, B, K, answer;
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
        int from, to;
        cin >> from >> to;
        Union(from, to);
    }
    cin >> A >> B >> K;
    
    for(int i = 1; i <= N; i++) {
        if(Find(i) == Find(A)) continue;
        if(Find(i) == Find(B)) continue;
        if(K > 0) {
            Union(i, A);
            K--;
        }
    }
    for(int i = 1; i <= N; i++) {
        if(Find(i) == Find(A)) answer++;
    }
    cout << answer;
    return 0;
}