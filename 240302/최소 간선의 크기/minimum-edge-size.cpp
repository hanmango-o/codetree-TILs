#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int N, M, A, B;
int parent[100001];
vector<tuple<int, int, int>> vect;

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
    cin >> A >> B;
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for(int i = 0; i < M; i++) {
        int from, to, vol;
        cin >> from >> to >> vol;
        vect.push_back(make_tuple(vol, from, to));
    }
    sort(vect.begin(), vect.end(), greater<tuple<int, int, int>>());
    for(int i = 0; i < M; i++) {
        int vol, from, to;
        tie(vol, from ,to) = vect[i];
        Union(from, to);
        if(Find(A) == Find(B)) {
            cout << vol;
            break;
        }
    }
    return 0;
}