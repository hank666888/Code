#include<iostream>
#include<stack>
using namespace std;

string str;

stack<int> s;

void cnt(){
    for(int i=0;i<str.size();i++){
        if(str[i]=='['){
            s.push(i);
        }
        else{
            cout<<s.top()<<" "<<i<<endl;
            s.pop();
        }
    }
}

int main(){
    cin>>str;
    cnt();
    return 0;
}
