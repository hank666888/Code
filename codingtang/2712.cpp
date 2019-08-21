#include<iostream>
#include<string>
using namespace std;

string str;
string ans;

int main(){
    getline(cin,str);
    for(int i=0;i<str.size()-1;i++)
        if(str[i]==' '){
            for(int j=i+1;j<str.size();j++){
                if(str[j]==' '){
                    break;
                }
                ans+=str[j];
            }
            break;
        }
    cout<<ans<<" "<<ans.size()<<endl;
    return 0;
}
