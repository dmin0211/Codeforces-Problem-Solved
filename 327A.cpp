#include <iostream>
#include <algorithm>
using namespace std;

int inputArray[105];
int n,ret;

void func(int start){
    int flip=0,sum;
    for (int i = start; i < n+1; ++i) {
        flip=inputArray[i]-inputArray[start-1];
//    cout<<flip<<"  ";
        ret=max(inputArray[n]-flip+(i-start+1-flip),ret);
//    cout<<ret<<endl;
    }
}

int main(){
    int temp=0;
    cin>>n;
    for (int i = 1; i < n+1; ++i) {
        cin>>temp;
        inputArray[i]=inputArray[i-1]+temp;
    }
    for (int i = 1; i < n+1; ++i) {
        func(i);
    }
    cout<<ret<<endl;
}