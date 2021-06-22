#include <iostream>
#include <algorithm>
using namespace std;

int n;
int inputNum[100005];

int main(){
    int max=0,min=0, max_next=0, min_next=0;
    cin>>n;
    cin>>inputNum[0];
    int index=0,answer=0;
    max=inputNum[0];
    min=inputNum[0];
    for (int i = 1; i < n; ++i) {
        cin>>inputNum[i];
        if(inputNum[i]>max) {
            max=inputNum[i];
            if(max-min!=1) {
                answer=std::max(int(i-index),answer);
                index = min_next + 1;
                min_next=max_next;
                min=max-1;
            }
        }
        else if(inputNum[i]<min) {
            min=inputNum[i];
            if(max-min!=1){
                answer=std::max(int(i-index),answer);
                index=max_next+1;
                max_next=min_next;
                max=min+1;
            }
        }
        if(inputNum[i]==min){
            min_next=i;
        }
        if(inputNum[i]==max){
            max_next=i;
        }
//    cout<<max_next<<"\t"<<min_next<<endl;
    }
    cout<<std::max(answer,n-index)<<endl;
}