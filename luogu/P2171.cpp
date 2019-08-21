#include<iostream>
using namespace std;

struct node{
    int data,left,right;
};

node tree[300010];

int n1;

int n;

int ans;

int newnode(int x){
    n++;
    tree[n].data=x;
    tree[n].left=tree[n].right=0;
    return n;
}

void insert(int x,int& idx){
    if(!idx){
        idx=newnode(x);
        return ;
    }
    if(x<tree[idx].data)
        insert(x,tree[idx].left);
    else    
        insert(x,tree[idx].right);
}

void dfs(int idx,int deep){
    if(!idx){
        ans=max(ans,deep);
        return ;
    }
    dfs(tree[idx].left,deep+1);
    dfs(tree[idx].right,deep+1);
}

void printhx(int idx){
    if(idx){
        printhx(tree[idx].left);
        printhx(tree[idx].right);
        cout<<tree[idx].data<<endl;
    }
}

int main(){
    cin>>n1;
    for(int i=1;i<=n1;i++){
        int x;
        cin>>x;
        int id=1;
        if(i==1)
            newnode(x);
        else
            insert(x,id);
    }
    dfs(1,0);
    cout<<"deep="<<ans<<endl;
    printhx(1);
    return 0;
}