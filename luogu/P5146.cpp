#include <iostream>
using namespace std;

int n,x;
int min_num=1e9,ans=-1;//赋初值。注意！求最大的要赋小的值，求最小的要赋大的值！

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x<min_num)
			min_num=x;//维护最小值
		ans=max(ans,x-min_num);//维护差的最大值
	}
	cout<<ans<<endl;//输出答案
	return 0;//完结撒花！
}