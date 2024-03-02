#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int N, M, A, B, K, answer;
int parent[100001], DAT[100001];
vector<pair<int, int>> vect;

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
        DAT[Find(from)]++;
    }

    for(int i = 1; i <= N; i++) {
        if(DAT[i] > 0) {
            vect.push_back(make_pair(DAT[i], i));
        }
    }
    cin >> A >> B >> K;
    
    sort(vect.begin(), vect.end(), greater<pair<int, int>>());

    for(int i = 0; i < vect.size(); i++) {
        int node, vol;
        tie(vol, node) = vect[i];

        if(Find(node) == Find(A)) continue;
        if(Find(node) == Find(B)) continue;
        if(K > 0) {
            Union(node, A);
            K--;
        }
    }
    for(int i = 1; i <= N; i++) {
        if(Find(i) == Find(A)) answer++;
    }
    cout << answer;
    return 0;
}