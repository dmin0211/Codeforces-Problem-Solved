#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>> energy;
int dp[1000005];

int findSmall(int high, int target){
    int low=0;
    int ans = -1; //못찾으면 -1
    while(low <= high){
        int m = low + (high-low)/2;
        if(energy[m].first < target){
            low = m + 1;
            ans = m;
        } else {
            high = m-1;
        }
    }
    return ans;
}

int main(){
    cin>>n;
    int tmp,tmp1;
    int answer=n;
    for (int i = 0; i < n; ++i) {
        cin>>tmp>>tmp1;
        energy.push_back({tmp,tmp1});
    }
    sort(energy.begin(),energy.end());
    dp[0]=0;
    for (int i = 1; i < n; ++i) {
        int find=findSmall(i,energy[i].first-energy[i].second);
//    cout<<find<<endl;
        if(find==-1) dp[i]=i;
        else dp[i]=dp[find]+(i-find-1);
    }
    for(int i=0;i<n;i++){
//    cout<<dp[i]<<endl;
        if((dp[i]+(n-i-1))<answer) answer=(dp[i]+(n-i-1));
    }
    cout<<answer<<endl;
}