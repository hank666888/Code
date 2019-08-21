#include<iostream>
using namespace std;

struct node{
    int data,left,right;
};

node tree[100010];
int n,x;

int ans;

int num;

void find(int idx){
    if(ans!=0)
        return ;
    if(tree[idx].left!=0)
        find(tree[idx].left);
    num++;
    if(tree[idx].data==x){
        ans=num;
        return ;
    }
    if(tree[idx].right!=0)
        find(tree[idx].right);
}

int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>tree[i].data>>tree[i].left>>tree[i].right;
    find(1);
    cout<<ans<<endl;
    return 0;
}