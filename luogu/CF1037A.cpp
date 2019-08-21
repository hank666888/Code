#include<iostream>
using namespace std;

long long a,ans;

int main()
{
    cin>>a;
    while(a){
        a/=2;
        ans++;
    }
    cout<<ans;
    return 0;
}