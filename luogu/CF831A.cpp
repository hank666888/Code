#include<iostream>
using namespace std;

int n,a[110];

bool flag1,flag2;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1])
            flag1=true;
        if(a[i]<a[i-1]){
            flag2=true;
            flag1=false;
        }
        if((flag2==true&&a[i]>=a[i-1])||(flag1==true&&a[i]!=a[i-1])){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}