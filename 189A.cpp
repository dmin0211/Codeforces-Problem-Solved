#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> input(3);
    int n=0;
    cin>>n>>input[0]>>input[1]>>input[2];
    sort(input.begin(),input.end());
//  for(int i=0;i<3;i++) {
//    cout<<input[i]<<"  ";
//  }cout<<endl;
    int temp=n, x=0, y=0, ret=0;
    int answer=temp/input[2];
    while(true){
        int tmp=temp;
        if(temp<=0) break;
//    cout<<temp<<endl;
        while(tmp>0){
//      cout<<"tmp:"<<tmp<<"  ret: "<<tmp/input[0]<<endl;
            if(tmp%input[0]==0){
                ret=tmp/input[0];
                tmp=0;
                break;
            }
            tmp-=input[1];
            y++;
//      cout<<y<<endl;
        }
        if(tmp==0){
            answer=max(answer,x+y+ret);
        }
        y=0;
        ret=0;
        temp-=input[2];
        x++;
    }
    cout<<answer<<endl;
}