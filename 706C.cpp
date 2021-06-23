#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> strings;
vector<string> reverseStrings;
long long dp[2][100005];
long long energy[100005];
int n;

int main(){
    cin>>n;
    fill(dp[0],dp[0]+100004,100000000000001);
    fill(dp[1],dp[1]+100004,100000000000001);
    for(int i=0;i<n;i++){
        cin>>energy[i];
    }
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        strings.push_back(temp);
        reverseStrings.push_back(temp);
    }
    for(int i=0;i<n;i++){
        reverse(reverseStrings[i].begin(),reverseStrings[i].end());
    }
    dp[0][0]=0;
    dp[1][0]=energy[0];
    for(int i=1;i<n;i++){
        if(strings[i-1]<=strings[i])
            dp[0][i]=dp[0][i-1];
        if(reverseStrings[i-1]<=strings[i])
            dp[0][i]=min(dp[0][i],dp[1][i-1]);
        if(strings[i-1]<=reverseStrings[i])
            dp[1][i]=dp[0][i-1]+energy[i];
        if(reverseStrings[i-1]<=reverseStrings[i])
            dp[1][i]=min(dp[1][i],dp[1][i-1]+energy[i]);
//    cout<<dp[1][i]<<"\t"<<dp[0][i]<<endl;
    }
//  func(0,0);
//  cout<<dp[1][n-1]<<"\t"<<dp[0][n-1]<<endl;
    if(dp[0][n-1]>=100000000000001&&dp[1][n-1]>=100000000000001) cout<<-1<<endl;
    else cout<<min(dp[1][n-1],dp[0][n-1])<<endl;
}