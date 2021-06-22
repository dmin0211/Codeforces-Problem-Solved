#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n=0;
vector<int> coin;

int main(){
    cin>>n;
    int sum=0,temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        coin.push_back(temp);
        sum+=temp;
    }
    temp=0;
    sort(coin.begin(),coin.end(),greater<int>());
    for(int i=0;i<n;i++){
        temp+=coin[i];
        if(temp>sum-temp) {
            cout<<i+1<<endl;
            break;
        }
    }
}