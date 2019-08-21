#include<iostream>
#include<string>
using namespace std;

string s;

bool empty(int id){
    if(id>=s.size()||s[id]=='#')
        return true;
    return false;
}

bool search(int id){
    if(empty(id))
        return true;
    bool l=search(id*2+1);
    bool r=search(id*2+2);
    if(l&&r&&(empty(id*2+1)==empty(id*2+2)))
        return true;
    return false;
}

int main(){
    cin>>s;
    if(search(0))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}