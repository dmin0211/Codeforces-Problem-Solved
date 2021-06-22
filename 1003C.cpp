#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;

int main(){
    int a=0;
    vector<int> aVector;
    double result;
    cin>>n>>k;
    cin>>a;
    aVector.push_back(a);
    if(k==1) result=a;
    for(int i=1;i<n;i++) {
        cin >> a;
        aVector.push_back(a + aVector[i - 1]);
        if (aVector.size()==k){
            result=(double) aVector[k-1]/k;
        }else if(aVector.size()>k){
            result=max(result,(double) aVector[i]/(i+1));
            for(int j=i-k;j>=0;j--){
                result=max(result,(double) (aVector[i]-aVector[j])/(i-j));
            }
        }
    }
    cout.precision(10);
    cout<< result;
}