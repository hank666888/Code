#include <iostream>
#include <cmath>
using namespace std;

double sum,ans;
int h,m;

int main(){
	long long x1,y1,x2,y2;
	cin>>x1>>y1;
	while(cin>>x1>>y1>>x2>>y2){
		sum+=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	}
	ans=sum*2/1000/20;
	h=ans;
	m=(ans-h)*60;
	if((ans-h)*60-m>=0.5)
		m++;
	cout<<h<<":";
	if(m<10)
		cout<<0;
	cout<<m<<endl;
	return 0;
}