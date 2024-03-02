#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

int N, M;
double answer;
pair<int, int> points[201];
vector<tuple<double, int, int>> vect;
int parent[201];

double getDist(int p1, int p2) {
    int x1, y1, x2, y2;
    tie(x1, y1) = points[p1];
    tie(x2, y2) = points[p2];
    return sqrt((double)(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

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
    for(int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }
    for(int i = 0; i < M; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        Union(p1, p2);
    }
    for(int i = 1; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) {
            if(Find(i) == Find(j)) continue;
            vect.push_back(make_tuple(getDist(i, j), i, j));
        }
    }
    sort(vect.begin(), vect.end());
    for(int i = 0; i < vect.size(); i++) {
        double dist;
        int from, to;
        tie(dist, from, to) = vect[i];
        if(Find(from) == Find(to)) continue;
        Union(from, to);
        answer += dist;
    }
    cout << fixed;
    cout.precision(2);
    cout << answer;
    return 0;
}