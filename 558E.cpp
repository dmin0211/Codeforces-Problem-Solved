#include<bits/stdc++.h>

using namespace std;
#define lson (k*2)
#define rson (k*2+1)
const int MAX = 100010;
const int MAX_V = 28;
class Node{
public:
    int l,r,v[MAX_V];
    Node();
    int mid(){
        return (l+r)/2;
    }
    int len(){
        return r-l+1;
    }
};
int Lazy[MAX*4][MAX_V];
int N,Q;
char str[MAX];
Node tree[MAX*4];
void PushUp(int k,int id){
    tree[k].v[id] = tree[lson].v[id] + tree[rson].v[id];
}
void PushDown(int k,int id){
    if(Lazy[k][id] != -1){
        int value = Lazy[k][id];
        tree[lson].v[id] = tree[lson].len()*value;
        tree[rson].v[id] = tree[rson].len()*value;
        Lazy[lson][id] = value;
        Lazy[rson][id] = value;
    }
    Lazy[k][id] = -1;
}
void Build(int L,int R,int k){
    tree[k].l = L;
    tree[k].r = R;
    if(L == R){
        int id = str[L]-'a';
        tree[k].v[id] = 1;
        return;
    }
    int mid = (L+R)/2;
    Build(L,mid,lson);
    Build(mid+1,R,rson);
    for(int i=0;i<26;++i)
        PushUp(k,i);
}
void Update(int L,int R,int add,int k,int id){
    if(L <= tree[k].l && tree[k].r <= R){
        tree[k].v[id] = add*tree[k].len();
        Lazy[k][id] = add;
        return;
    }
    PushDown(k,id);
    int mid = tree[k].mid();
    if(L <= mid)    Update(L,R,add,lson,id);
    if(R > mid) Update(L,R,add,rson,id);
    PushUp(k,id);
}
int Query(int L,int R,int k,int id){
    if(L <= tree[k].l && tree[k].r <= R)
        return tree[k].v[id];
    PushDown(k,id);
    int res = 0;
    int mid = tree[k].mid();
    if(L <= mid)    res += Query(L,R,lson,id);
    if(R > mid)     res += Query(L,R,rson,id);
    return res;
}
void Display(){
    for(int i=1;i<=N;++i){
        for(int id=0;id<26;++id){
            if(Query(i,i,1,id)){
                printf("%c",'a'+id);
            }
        }
    }
    printf("\n");
}
void Show(int *bas){
    for(int id=0;id<26;++id){
        printf("%d ",bas[id]);
    }
    printf("\n");
}
int main(void){
    //Lzay should be set to -1 here, because the update value may be 0, pay attention.
    memset(Lazy,-1,sizeof(Lazy));
    scanf("%d%d",&N,&Q);
    scanf("%s",str+1);
    Build(1,N,1);
    int u,v,w;
    int bas[MAX_V];//Store the number of each character
    for(int i=1;i<=Q;++i){
        scanf("%d%d%d",&u,&v,&w);
        if(w == 0){
            //Query the number of each character in the interval.
            for(int id=0;id<26;++id){
                bas[id] = Query(u,v,1,id);
                Update(u,v,0,1,id);
            }
            int l=u,r;
            //0 means descending order, that is, the characters in the corresponding interval are updated from back to front.
            for(int id=25;id>=0;--id){
                if(bas[id]){
                    r = l+bas[id]-1;
                    Update(l,r,1,1,id);
                    l += bas[id];
                }
            }
        }
        else{
            for(int id=0;id<26;++id){
                bas[id] = Query(u,v,1,id);
                Update(u,v,0,1,id);
            }
            int l=u,r;
            for(int id=0;id<26;++id){
                if(bas[id]){
                    r = l + bas[id]-1;
                    Update(l,r,1,1,id);
                    l += bas[id];
                }
            }
        }

    }
    Display();
    return 0;
}
Node::Node(){
    l = r = 0;
    memset(v,0,sizeof(v));
}