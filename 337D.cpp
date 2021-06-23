#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[1000005];
bool flag[100005];
int subTree[100005][2], outerTree[100005], p[100005];

int dfs(int node, int parent) {
    subTree[node][0] = subTree[node][1] = -2000000;
    p[node] = parent;
    for (int i = 0; i < adj[node].size(); i++) {
        if (adj[node][i] != parent) {
            int temp = dfs(adj[node][i], node) + 1;
            if (temp > subTree[node][0])
                subTree[node][1] = subTree[node][0], subTree[node][0] = temp;
            else if (temp > subTree[node][1])
                subTree[node][1] = temp;
        }
    }
    if (flag[node]) {
        if (subTree[node][0] < 0)
            subTree[node][0] = 0;
        else
            subTree[node][1] = max(subTree[node][1], 0);
    }
    return subTree[node][0];
}

void dfs2(int node, int parent) {
    outerTree[node] = -2000000;
    if (parent) {
        if (subTree[parent][0] == subTree[node][0] + 1)
            outerTree[node] = subTree[parent][1] + 1;
        else
            outerTree[node] = subTree[parent][0] + 1;
        outerTree[node] = max(outerTree[node], outerTree[parent] + 1);
    }
    for (int i = 0; i < adj[node].size(); i++) {
        if (adj[node][i] != parent)
            dfs2(adj[node][i], node);
    }
}

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        flag[a] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0), dfs2(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (subTree[i][0] <= d && outerTree[i] <= d)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
