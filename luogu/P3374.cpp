#include <cstdio>

const int MAXN=500010;

int n,m;

int a[MAXN];

int lowbit(int x){
	return x&(-x);
}

void add(int x,int d){
	while(x<=n){
		a[x]+=d;
		x+=lowbit(x);
	}
}

int sum(int x){
	int ret=0;
	while(x>0){
		ret+=a[x];
		x-=lowbit(x);
	}
	return ret;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		add(i,x);
	}
	while(m--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
			add(b,c);
		else
			printf("%d\n",sum(c)-sum(b-1));
	}
	return 0;
}