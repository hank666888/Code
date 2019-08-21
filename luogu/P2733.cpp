#include<iostream>
using namespace std;

int n;
int sum[255][255];
int ans[255];
char ch;

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>ch;
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+ch-48;//前缀和部分 
        }
    for(int k=2;k<=n;k++)
    {
        int area=k*k; 
        for(int i=1;i<=n-k+1;i++)
	        for(int j=1;j<=n-k+1;j++)
                if(sum[i-1][j-1]+sum[i+k-1][j+k-1]-sum[i+k-1][j-1]-sum[i-1][j+k-1]==area) 
                	ans[k]++;
    }
    for(int i=2;i<=250;i++) 
    	if(ans[i]>0) 
    		cout<<i<<" "<<ans[i]<<endl;
    return 0;
}