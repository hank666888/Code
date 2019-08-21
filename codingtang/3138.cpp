#include<iostream>
using namespace std;

int m,n,mw[33333],mv[33333],fw[33333][3],fv[33333][3],f[33333],v,p,q;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>v>>p>>q;
        if(!q){
            mw[i]=v;
            mv[i]=v*p;
        }
        else{
            fw[q][0]++;
            fw[q][fw[q][0]]=v;
            fv[q][fw[q][0]]=v*p;
        }
    }
    for(int i=1;i<=m;i++)
    for(int j=n;j>=mw[i];j--){
        f[j]=max(f[j],f[j-mw[i]]+mv[i]);
        if(j>=mw[i]+fw[i][1])
            f[j]=max(f[j],f[j-mw[i]-fw[i][1]]+mv[i]+fv[i][1]);
        if(j>=mw[i]+fw[i][2])
            f[j]=max(f[j],f[j-mw[i]-fw[i][2]]+mv[i]+fv[i][2]);
        if(j>=mw[i]+fw[i][1]+fw[i][2])
            f[j]=max(f[j],f[j-mw[i]-fw[i][1]-fw[i][2]]+mv[i]+fv[i][1]+fv[i][2]);
    }
    cout<<f[n]<<endl;
    return 0;
}
