#include <iostream>
#include <algorithm>
using namespace std;

struct usb{
	int w,v;
}a[10010];

bool cmp(usb a,usb b){
	return a.w<b.w;
}

int n,p,m;

int f[10010];

int main(){
	cin>>n>>p>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].w>>a[i].v;
	}
	sort(a,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=m;j>=a[i].w;j--){
			f[j]=max(f[j],f[j-a[i].w]+a[i].v);
			if(f[m]>=p){
				cout<<a[i].w<<endl;
				return 0;
			}
		}
	}
	cout<<"No Solution!"<<endl;
	return 0;
}