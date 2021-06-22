#include <iostream>
#include <vector>
using namespace std;

int main(){
    int testCase=0,n=0,temp;
    long long sum;
    cin>>testCase;
    for(int i=0;i<testCase;i++){
        vector<int> a;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>temp;
            sum+=temp;
            a.push_back(temp);
        }
        long long maxCurrent=a[0], maxSum=a[0];
        for(int j=1;j<n-1;j++){
            if(maxCurrent<0) maxCurrent=a[j];
            else maxCurrent+=a[j];
            maxSum=max(maxSum,maxCurrent);
        }
        maxCurrent=a[1];
        for(int j=2;j<n;j++){
            if(maxCurrent<0) maxCurrent=a[j];
            else maxCurrent+=a[j];
            maxSum=max(maxSum,maxCurrent);
        }
        maxSum=max(maxSum,maxCurrent);
        if(maxSum<sum) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        sum=0;
    }
}