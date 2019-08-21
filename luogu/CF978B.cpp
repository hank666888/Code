#include<iostream>
#include<string>
using namespace std;

string str;
int ans;

int main()
{
    int size;
    cin>>size;
    cin>>str;
    for(int i=0;i<=size-3;i++){
        if(str[i]=='x'){
            int k=0;
            while(str[i]=='x'){
                i++;
                k++;
            }
            if(k>=3)
                ans+=k-2;
        }
    }
    cout<<ans<<endl;
    return 0;
}
