#include <iostream>
#include <vector>
using namespace std;

int resultCount=0,n=0;
vector<int> groupCount(3,0);

int main(){
    cin>>n;
    int temp=0;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(temp==4) resultCount++;
        else groupCount[temp-1]++;
    }
    resultCount=resultCount+groupCount[2]+groupCount[1]/2;
    temp=min(groupCount[2],groupCount[0]);
    groupCount[0]-=temp;
    if(groupCount[0]<=0) resultCount+=groupCount[1]%2;
    else {
        resultCount+=groupCount[1]%2;
        groupCount[0]-=(groupCount[1]%2)*2;
    }
    if(groupCount[0]>0) {
        resultCount+=groupCount[0]/4;
        if(groupCount[0]%4!=0) resultCount++;
    }
    cout<<resultCount<<endl;
}