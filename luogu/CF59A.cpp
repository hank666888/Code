#include<iostream>
#include<string>
using namespace std;

string str;
int num_b,num_s;

int main(){
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(str[i]>='a'&&str[i]<='z')
            num_s++;
        else
            num_b++;
    }
    if(num_s>=num_b){
        for(int i=0;i<str.size();i++){
            if(str[i]>='A'&&str[i]<='Z')
                str[i]+=32;
            cout<<str[i];
        }
        cout<<endl;
    }
    else{
        for(int i=0;i<str.size();i++){
            if(str[i]>='a'&&str[i]<='z')
                str[i]-=32;
            cout<<str[i];
        }
        cout<<endl;
    }
    return 0;
}