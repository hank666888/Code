#include<iostream>
using namespace std;

int n,m,f[10010];

void init(){
    for(int i=1;i<=n;i++)
        f[i]=i;
}

int main(){
    while(cin>>n>>m,n&&m){
        init();
        for(int i=1;i<=m;i++){
            int u,v;
            f[v]=f[u];
        }
    }
}
