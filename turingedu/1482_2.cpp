#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int n,len=1,f[5003][5003];
void fb(int k){
    int i;
    for(i=1;i<=len;i++)
		for(int j=1;j<=k;j++)
        	f[k][i]+=f[k-j][i];
    for(i=1;i<=len;i++)
        if(f[k][i]>=10){
            f[k][i+1]+=f[k][i]/10;
            f[k][i]=f[k][i]%10;
            if(f[k][len+1])
                len++;
        }
}
int main()
{
    int i;
    scanf("%d",&n);
	for(int i=1;i<=n;i++)
		f[i][1]=1;
    f[2][1]=2;
    for(i=3;i<=n;i++)
        fb(i);
    for(i=len;i>=1;i--)
        printf("%d",f[n][i]);
    return 0;
}
