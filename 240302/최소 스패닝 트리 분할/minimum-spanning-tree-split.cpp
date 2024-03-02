#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int N, M, answer, lastVol;
int parent[10001];
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
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < M; i++) {
        int from, to, vol;
        cin >> from >> to >> vol;
        vect.push_back(make_tuple(vol, from, to));
    }
    sort(vect.begin(), vect.end());
    for(int i = 0; i < vect.size(); i++) {
        int vol, from, to;
        tie(vol, from, to) = vect[i];
        if(Find(from) == Find(to)) continue;
        Union(from, to);
        answer += vol;
        lastVol = vol;
    }
    cout << answer - lastVol;
    return 0;
}