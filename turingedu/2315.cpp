#include<iostream>
using namespace std;

int n,m,a[310];
int lef,rig,mid;
int total,tim;

bool judge(int x){
    for(int i=1;i<=n;i++){
        if(total+a[i]<=x)
            total+=a[i];
        else 
            total=0,tim++;
    }
    return tim>=m;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        rig+=a[i];
        lef=lef<a[i]?lef:a[i];
    }
    while(lef<=rig){
        mid=(lef+rig)/2;
        total=0,tim=0;
        if(judge(mid))
            lef=mid+1;
        else 
            rig=mid-1;
    }
    cout<<lef<<endl;
    return 0;
}