#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int parent[100001];
vector<int> vect[100001];

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

    int a = Find(1);
    int b;

    for(int i = 1; i <= N; i++) {
        if(Find(i) != a) b = Find(i);
        vect[Find(i)].push_back(i);
    }

    sort(vect[a].begin(), vect[a].end());
    sort(vect[b].begin(), vect[b].end());
    
    if(vect[a][0] > vect[b][0]) {
        cout << vect[b][0] << " " <<  vect[a][0];
    } else {
                cout << vect[a][0] << " " <<  vect[b][0];
    }
    

    return 0;
}