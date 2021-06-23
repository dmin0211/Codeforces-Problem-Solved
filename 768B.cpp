#include <iostream>
using namespace std;

long long n,r,l,answer=0;

void solve(long long rangeL,long long rangeR,long long currentNum){
    if(rangeR<rangeL) return;
    long long mid=(rangeL+rangeR)/2;
//  cout<<currentNum<<"\tmid:"<<mid<<endl;
    if(r<mid) solve(rangeL,mid-1,currentNum/2);
    else if(l>mid) solve(mid+1,rangeR,currentNum/2);
    else{
        answer+=currentNum%2;
//    cout<<"answer:"<<answer<<endl;
        solve(rangeL,mid-1,currentNum/2);
        solve(mid+1,rangeR,currentNum/2);
    }
}

int main(){
    cin>>n>>l>>r;
    long long length=1, temp=n;
    while(temp>=2){
        temp/=2;
        length=2*length+1;
    }
    solve(1,length,n);
    cout<<answer<<endl;
}