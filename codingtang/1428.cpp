#include<iostream>
using namespace std;
int main(){
    int n,c,d,e=0;
    cin>>n;
    int a[n],b[n];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    for(int i=1;i<=n-1;++i){
        c=a[i];
        for(int j=i+1;j<=n;++j){
            d=a[j];
            for(int k=1;k<=n;++k){
                if(b[k]==c+d){
                    e++;
                    b[k]=0;
                }
            }
        }
    }
    cout<<e;
    return 0;
}
