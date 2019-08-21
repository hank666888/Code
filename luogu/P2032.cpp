#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
#define mp make_pair
typedef pair <int,int> pill ; 
priority_queue <pill,vector<pill>,less<pill> > q;
int n,m,k,a[2000006];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        q.push(mp(a[i],i)); 
        if(i>=k){
            while(q.top().second<=i-k)
            	q.pop();
            printf("%d\n",q.top().first);
        }
    }
    return 0;
}