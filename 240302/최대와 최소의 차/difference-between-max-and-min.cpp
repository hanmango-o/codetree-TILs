#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

int N, M, maxAnswer, minAnswer;
vector<tuple<int, int, int>> vect;
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

void init() {
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }
}

int main() {
    cin >> N >> M;
    init();
    for(int i = 0; i < M; i++) {
        int from, to, vol;
        cin >> from >> to >> vol;
        vect.push_back(make_tuple(!vol, from ,to));
    }
    sort(vect.begin(), vect.end(), greater<tuple<int, int, int>>());
    for(int i = 0; i < vect.size(); i++) {
        int vol, from, to;
        tie(vol, from, to) = vect[i];
        if(Find(from) == Find(to)) continue;
        Union(from, to);
        maxAnswer += vol;
    }
    init();
    for(int i = vect.size() - 1; i >= 0; i--) {
        int vol, from, to;
        tie(vol, from, to) = vect[i];
        if(Find(from) == Find(to)) continue;
        Union(from, to);
        minAnswer += vol;
    }
    cout << pow(maxAnswer, 2) - pow(minAnswer, 2);
    return 0;
}