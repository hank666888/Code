#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const int MAXN=1e6+10;

int Max[MAXN][21];
int Query(int l,int r){
    int k=log2(r-l+1); 
    return max(Max[l][k],Max[r-(1<<k)+1][k]);
}

int main(){
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++) 
        cin>>Max[i][0];
    for(int j=1;j<=21;j++)
        for(int i=1;i+(1<<j)-1<=N;i++) 
            Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
    for(int i=1;i<=M;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",Query(l,r));
    }
    return 0;
}