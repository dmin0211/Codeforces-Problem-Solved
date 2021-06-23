#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int root[1010];
bool is_root[1010];
int ran[1010];
vector <pair<int, int>> node;

int fi(int a){
    if(root[a]==a) return a;
    else return root[a]=fi(root[a]);
}

void uni(int a, int b){
    int ra=fi(a);
    int rb=fi(b);
    if(ra==rb) return;
    if(ran[ra]<ran[rb]){
        root[ra]=rb;
    }else{
        root[rb]=ra;
        if(ran[ra]==ran[rb]) ran[rb]++;
    }
}

int main(int argc, char *argv[])
{
    cin>>n;
    int x, y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        node.push_back({x,y});
        root[i]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            if(j==i)continue;
            if(node[i].first == node[j].first || node[i].second == node[j].second) {
                uni(i,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        int index=fi(i);
        is_root[index]=true;
    }
    int cnt=-1;
    for(int i=0;i<n;i++){
        if(is_root[i]) cnt++;
    }
    cout<<cnt<<endl;
}