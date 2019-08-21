#include<iostream>
#include<stack>
using namespace std;

stack<int> s;
int n,a[1010];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int j=1;
    for(int i=1;i<=n;i++){
        s.push(i);
        while(!s.empty()&&s.top()==a[j]){
            s.pop();
            j++;
        }
    }
    if(s.empty())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
