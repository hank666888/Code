#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n,i=1;
    cin>>n;
    queue<long long> q;
    q.push(1);
    while(true){
        long long x=q.front();
        if(i==n){
            cout<<x<<endl;
            break;
        }
        q.pop();
        q.push(2*x+1);
        i++;
    }
    return 0;
}
