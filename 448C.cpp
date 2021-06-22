#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[5001];

int paintingSubFence(int front, int end){
    int temp = *min_element(&arr[front],&arr[end]+1);
    if(temp>=end-front+1) return (end-front+1);
    for(int i=front;i<end+1;i++) arr[i]-=temp;
    int index=front;
    for(int i=front;i<end+1;i++){
        if(arr[i]==0){
            if(i==front) index++;
            else if(arr[i-1]==0) index++;
            else {
                temp+=paintingSubFence(index,i-1);
                index=i+1;
            }
        }
    }
    if(arr[end]!=0) temp+=paintingSubFence(index,end);
    if(temp>=end-front+1) return (end-front+1);
    return temp;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];
    int answer=paintingSubFence(0,N-1);
    cout<<answer<<endl;
}