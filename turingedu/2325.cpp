#include <iostream>
using namespace std;

int a,b;

int ans,i;

int get1(int x){
	for(int i=x;;i++){
		if(i%4==0&&(i%100!=0||i%400==0))
			return i;
	}
}

int get2(int x){
	for(int i=x;;i--){
		if(i%4==0&&(i%100!=0||i%400==0))
			return i;
	}
}

int main(){
	cin>>a>>b;
	i=get1(a);
	while(true){
		int k=i/100*100+100;
		if(k>b)
			k=get2(b);
		ans+=(k-i)/4+1;
		if(k%100==0&&k%400!=0)
			ans--;
		i=k+4;
		if(i>=get2(b))
			break;
	}
	cout<<ans<<endl;
	return 0;
}