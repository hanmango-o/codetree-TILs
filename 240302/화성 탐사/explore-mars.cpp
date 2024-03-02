#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int N, cnt, answer;
int MAP[50][50], dist[50][50];
bool visited[50][50];
pair<int, int> parent[50][50];

pair<int, int> S;
vector<tuple<int, int, int, int, int>> vect;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

pair<int, int> Find(pair<int, int> tar) {
    if(tar.first == parent[tar.first][tar.second].first && tar.second == parent[tar.first][tar.second].second) return tar;
    pair<int, int> ret = Find(parent[tar.first][tar.second]);
    parent[tar.first][tar.second] = ret;
    return ret;
}

void Union(pair<int, int> a, pair<int, int> b) {
    pair<int, int> pa = Find(a);
    pair<int, int> pb = Find(b);
    if(pa.first == pb.first && pa.second == pb.second) return;
    parent[pb.first][pb.second] = pa;
    cnt--;
}

void BFS(int startY, int startX) {
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
    //         dist[i][j] = 0;
    //     }
    // }
    fill(&dist[0][0], &dist[N][N], 0);
    queue<pair<int, int>> q;
    q.push(S);
    dist[startY][startX] = 1;

    while(!q.empty()) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int newY = y + dy[i];
            int newX = x + dx[i];
            if(newY < 0 || newY >= N || newX < 0 || newX >= N || dist[newY][newX] > 0 || MAP[newY][newX] == -1 || visited[newY][newX]) continue;
            dist[newY][newX] = dist[y][x] + 1;
            if(MAP[newY][newX] > 0) {
                vect.push_back(make_tuple(dist[newY][newX] - 1, startY, startX, newY, newX));
            }
            q.push(make_pair(newY, newX));
        }
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            parent[i][j] = {i, j};
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> MAP[i][j];
            if(MAP[i][j] == 1) {
                S = {i, j};
                cnt++;
            } else if(MAP[i][j] == 2) {
                cnt++;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(MAP[i][j] > 0) {
                visited[i][j] = true;
                BFS(i, j);
            }
        }
    }
    sort(vect.begin(), vect.end());

    for(int i = 0; i < vect.size(); i++) {
        int vol, fromY, fromX, toY, toX;
        tie(vol, fromY, fromX, toY, toX) = vect[i];
        pair<int, int> from = Find(make_pair(fromY, fromX));
        pair<int, int> to = Find(make_pair(toY, toX));
        if(from.first == to.first && from.second == to.second) continue;
        Union(make_pair(fromY, fromX), make_pair(toY, toX));
        answer += vol;
    }

    cout << (cnt == 1 ? answer : -1);

    return 0;
}