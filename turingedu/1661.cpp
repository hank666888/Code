#include<iostream>
using namespace std;

long long ans,w;
long long h[10010],n;

int main(){
    cin>>n>>w;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    for(int i=1;i<=n;i++){
        int min_h=1e9;
        for(int j=i;j<=n;j++){
            min_h=min_h<h[j]?min_h:h[j];
            ans=ans>min_h*(j-i+1)*w?ans:min_h*(j-i+1)*w;
        }
    }
    cout<<ans<<endl;
    return 0;
}