#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long long> a;
int main(){
    int inputNumber = 0;
    long long total, count=0, middleCount=0;
    cin>>N;
    cin>>inputNumber;
    a.push_back(inputNumber);
    for(int i=1;i<N;i++){
        cin>>inputNumber;
        a.push_back(a[i-1]+inputNumber);
    }
    total=a[N-1];
    if(total%3!=0){
        cout<<0<<endl;
    }else {
        if (a[0] == total / 3) middleCount++;
        for (int i = 1; i < N - 1; i++) {
            if (a[i] == total / 3 * 2) count += middleCount;
            if (a[i] == total / 3) middleCount++;
        }
        cout << count << endl;
    }
}