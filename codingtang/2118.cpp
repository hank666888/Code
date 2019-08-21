#include<iostream>
#include<string>
using namespace std;

string s;

bool search(){
    for(int i=0;i<s.size();i++){
        if(i*2+1<s.size()&&i*2+2>=s.size())
            return false;
        if(i*2+2<s.size())
            if((s[i*2+1]=='#'&&s[i*2+2]!='#')||(s[i*2+1]!='#'&&s[i*2+2]=='#'))
                return false;
    }
    return true;
}

int main(){
    cin>>s;
    if(search())
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}