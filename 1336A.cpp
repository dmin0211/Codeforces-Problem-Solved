#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
vector<long long> edge[200005];
vector<long long> answer;
long long distanceArr[200005];
long long children[200005];
bool visit[200005];


int n,k;

int bfs(int node){
    long long current=distanceArr[node];
    long long child=0;
    for (int i = 0; i < edge[node].size(); ++i) {
        long long next=edge[node][i];
    cout<<node<<"next:"<<next<<endl;
        if(!visit[next]){
            visit[next]=true;
            distanceArr[next]=current+1;
            child+=bfs(next);
        }
    }
  cout<<"node:"<<node<<"\t"<<edge[node].size()-1<<"\t"<<child<<"\t"<<distanceArr[node]<<endl;
  cout<<"distance:"<<current<<endl;
    children[node]=edge[node].size()+child-1;
    answer.push_back((distanceArr[node]-children[node]));
    return children[node];
}

int main(){
    int u,v;
    long long result=0;
    cin>>n>>k;
    memset(visit,false,sizeof(visit));
    for (int i = 0; i < n-1; ++i) {
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    visit[1]=true;
    bfs(1);
    sort(answer.begin(),answer.end(),greater<int>());
    for (int i = 0; i < k; ++i) {
        result+=answer[i];
    }
}