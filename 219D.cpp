#include <iostream>
#include <vector>
#include <algorithm>

//뒤집음 :1 정방향 :0

using namespace std;
vector<pair<int, int>> edge[200005];

int tree_dp[200005];

void dfs(int index, int parent) {
    tree_dp[index] = 0;
    for (int i = 0; i < edge[index].size(); ++i) {
        int child = edge[index][i].first;
        int direction = edge[index][i].second;
        if (child == parent) continue;
        dfs(child, index);
        if (direction == 0) {
            tree_dp[index] += tree_dp[child];
        } else {
            tree_dp[index] += (tree_dp[child] + 1);
        }
    }
}

void dfs2(int index, int parent) {
    for (int i = 0; i < edge[index].size(); ++i) {
        int child = edge[index][i].first;
        if (child == parent) continue;
        tree_dp[child] = tree_dp[index] + (edge[index][i].second ? -1:1);
        dfs2(child,index);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int temp, temp2;
        cin >> temp >> temp2;
        edge[temp].push_back({temp2, 0});
        edge[temp2].push_back({temp, 1});
    }
    dfs(1,-1);
    dfs2(1,-1);
    int min=200005;
    vector<int> answer;
    for (int i = 1; i <= n; ++i) {
        if(min>tree_dp[i]){
            min=tree_dp[i];
            answer.clear();
            answer.push_back(i);
        }else if(min==tree_dp[i]){
            answer.push_back(i);
        }
    }
    cout<<min<<endl;
    for (int i = 0; i < answer.size(); ++i) {
        cout<<answer[i]<<" ";
    }cout<<endl;
}