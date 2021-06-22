#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long input[100010];
long long DP[100010];

int main(){
    int n=0,temp=0;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>temp;
        input[temp]++;
    }
    for(int i=100000;i>=0;i--){
        DP[i]=max(DP[i+2]+input[i]*i,DP[i+3]+input[i+1]*(i+1));
    }
    printf("%lld\n",DP[1]);
}