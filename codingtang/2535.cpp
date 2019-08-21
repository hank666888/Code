#include<iostream>
using namespace std;

int n;
int a[41][41];

int main(){
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++){
        cout<<a[i][i]<<" ";
        ans+=a[i][i];
    }
    cout<<endl<<ans<<endl;
    return 0;
}
