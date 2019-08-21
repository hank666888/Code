#include<iostream>
#include<queue>
using namespace std;

priority_queue<int,vector<int>,greater<int> > q;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==1){
            int num;
            cin>>num;
            q.push(num);
        }
        if(x==2){
            cout<<q.top()<<endl;
        }
        else if(x==3){
            q.pop();
        }
    }
    return 0;
}
