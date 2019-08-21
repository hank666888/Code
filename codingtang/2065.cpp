#include<iostream>
#include<stack>
using namespace std;

stack<char> s;

int main(){
    char c;
    bool flag=false;
    while(cin>>c,c!='@'){
        if(c=='(')
            s.push(c);
        else if(c==')'){
            if(s.empty()){
                flag=true;
                break;
            }
            s.pop();
        }
    }
    if(!flag&&s.empty())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
