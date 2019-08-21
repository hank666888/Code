#include<iostream>
#include<stack>
using namespace std;

stack<long long> s;

int main(){
    long long x=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        x*=2;
        x++;
        s.push(x);
    }
    cout<<s.top()<<endl;
    return 0;
}
