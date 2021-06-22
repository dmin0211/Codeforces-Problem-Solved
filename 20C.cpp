#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL)
using namespace std;

long long n, m;
long long dist[100010], path[100010];
vector<pair<long long, long long>> edge[100010];
bool visit[100010];

void dijkstra(int s) {
    priority_queue<pair<long long, long long>> q;
    q.push({s, 0});
    while (!q.empty()) {
        long long current = q.top().first;
        long long distance = q.top().second;
        q.pop();
        if (distance != dist[current]) continue;
        for (int i = 0; i < edge[current].size(); ++i) {
            long long next = edge[current][i].first;
            long long next_distance = edge[current][i].second;
            if (dist[next] > next_distance + distance || dist[next] == 0) {
                dist[next] = next_distance + distance;
                path[next] = current;
                q.push({next, dist[next]});
            }
        }
    }
}

int main() {
    FIO;
    cin >> n >> m;
    int x, y, w;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> w;
        edge[x].push_back({y, w});
        edge[y].push_back({x, w});
    }
    dijkstra(1);
    if (path[n] == 0) {
        cout << -1 << endl;
    } else {
        vector<long long> answer;
        long long index = n;
        path[1] = 1;
        while (true) {
            if (path[index] >= 1 && path[index] < n && visit[index] == false) {
                answer.push_back(index);
                visit[index] = true;
                index = path[index];
            } else {
                break;
            }
        }
        for (int i = answer.size() - 1; i >= 0; --i) {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
}