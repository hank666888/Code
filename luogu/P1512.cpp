#include<iostream>
using namespace std;
int year,month,day,n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>year>>month>>day;
        if((month+day)%2==0||(month==9&&day==30)||(month==1&&day==30))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}