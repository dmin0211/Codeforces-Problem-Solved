#include <iostream>
#include <string>
using namespace std;

int main(){
    int n,length;
    char first, end;
    string str;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str;
        length=str.length();
        if(length>10){
            end=str[length-1];
            first=str[0];
            str.clear();
            cout<<first<<length-2<<end<<endl;
        }else cout<<str<<endl;
    }
}