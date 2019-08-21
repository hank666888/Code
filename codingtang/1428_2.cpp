#include<iostream>
#include<cstdio>
using namespace std;
int n,a[105],cnt,b[20000];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]=1;
    }
    for(int i=1;i<=n-1;i++)
        for(int j=i+1;j<=n;j++)
            if(b[a[i]+a[j]]==1){
                b[a[i]+a[j]]=0;
                cnt++;
            }
    cout<<cnt<<endl;
    return 0;
}