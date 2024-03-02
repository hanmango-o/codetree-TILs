#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int N, M, answer;
vector<tuple<int, int, int, int, int>> vect;
pair<int, int> parent[301][301];

pair<int, int> Find(pair<int, int> tar) {
    pair<int, int> ptar = parent[tar.first][tar.second];
    if(tar.first == ptar.first && tar.second == ptar.second) return tar;
    pair<int, int> ret = Find(ptar);
    parent[tar.first][tar.second] = ret;
    return ret;
}

void Union(pair<int, int> a, pair<int, int> b) {
    pair<int, int> pa = parent[a.first][a.second];
    pair<int, int> pb = parent[b.first][b.second];
    if(pa.first == pb.first && pa.second == pb.second) return;
    parent[pb.first][pb.second] = pa;
}

int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            parent[i][j] = {i, j};
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j < M; j++) {
            int vol;
            cin >> vol;
            vect.push_back(make_tuple(vol, i, j, i, j + 1));
        }
    }
    for(int i = 1; i < N; i++) {
        for(int j = 1; j <= M; j++) {
            int vol;
            cin >> vol;
            vect.push_back(make_tuple(vol, i, j, i + 1, j));
        }
    }

    sort(vect.begin(), vect.end());

    for(int i = 0; i < vect.size(); i++) {
        int vol, fromY, fromX, toY, toX;
        tie(vol, fromY, fromX, toY, toX) = vect[i];
        pair<int, int> pfrom = Find(make_pair(fromY, fromX));
        pair<int, int> pto = Find(make_pair(toY, toX));
        if(pfrom.first == pto.first && pfrom.second == pto.second) continue;
        Union(pfrom, pto);
        answer += vol;
    }
    
    cout << answer;
    
    return 0;
}