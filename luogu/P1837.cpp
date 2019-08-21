#include<iostream>
using namespace std;

int n,m;
int tree[1000010];
int l=1,r;

bool check(int k){
    int sum=0;
    for(int i=1;i<=n;i++)
        if(tree[i]>k)
            sum+=tree[i]-k;
    return sum>=m;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>tree[i];
        r=max(r,tree[i]);
    }
    while(l<r){
        int mid=(l+r)/2;
        if(check(l))
            l=mid-1;
        else
            r=mid-1;
    }
    cout<<l<<endl;
    return 0; 
}