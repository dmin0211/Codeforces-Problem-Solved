//fail
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
vector<vector<long long>> nodeEdge(100005);
bool visit[100005];

void dijkstra(double &count, double &distanceCount){
    queue<pair<long long,long long>> q;
    q.push({1,0});
    visit[1]=false;
    while(!q.empty()){
        long long node=q.front().first;
        long long distance=q.front().second;
        q.pop();
        for(int i=0;i<nodeEdge[node].size();i++){
            long long nextNode=nodeEdge[node][i];
            long long nextDistance=distance+1;
            if(visit[nextNode]){
                visit[nextNode]=false;
                if(nodeEdge[nextNode].size()==1) {
                    count++;
                    distanceCount+=nextDistance;
                }else{
                    q.push({nextNode,nextDistance});
                }
            }
        }
    }
}

int main(){
    cin>>n;
    int index, temp;
    double count=0,distanceCount=0;
    memset(visit,true,100005);
    for (int i = 0; i < n-1; i++) {
        cin>>index>>temp;
        nodeEdge[index].push_back(temp);
        nodeEdge[temp].push_back(index);
    }
    dijkstra(count,distanceCount);
    double answer=distanceCount/count;
    cout.precision(11);
    cout<<fixed<<answer<<endl;
}