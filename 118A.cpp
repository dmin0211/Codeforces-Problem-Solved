#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> vowels ={'a','o','y','e','u','i'};

int main(){
    string str;
    cin>>str;
    transform(str.begin(),str.end(),str.begin(),::tolower);
    for(int i=0; i<str.length();i++){
        if(find(vowels.begin(),vowels.end(),str[i])==vowels.end()){
            cout<<'.'<<str[i];
        }
    }cout<<endl;
}