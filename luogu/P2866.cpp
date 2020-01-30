#include<iostream>
#include<stack>
using namespace std;
 
stack<int> s;
 
int a[100010];
 
long long ans;
 
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
     for(int i=1;i<=n;i++){
        while(!s.empty()&&a[i]>=s.top())
            s.pop();
        ans+=s.size();
        s.push(a[i]);
    }
    cout<<ans<<endl;
    return 0;
}