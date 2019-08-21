#include<iostream>
#include<stack>
using namespace std;

stack<char> s;
int main(){
    char c;
    bool flag=false;
    while(cin>>c){
        if(c=='('||c=='[')
            s.push(c);
        else{
            if(s.empty()||(c==')'&&s.top()=='['||c==']'&&s.top()=='(')){
                flag=true;
                break;
            }
            s.pop();
        }
    }
    if(!flag&&s.empty())
        cout<<"OK"<<endl;
    else
        cout<<"Wrong"<<endl;
    return 0;
}
