#include <iostream>
#include <queue>//STL是个好东西
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;//小根堆标准定义
int a[1000010],n;
long long ans;//注意最终答案会爆int!要用long long存！

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pq.push(a[i]);
	}//输入+预处理
	for(int i=1;i<=n-1;i++){
		int a=pq.top();//取出最小元素
		pq.pop();
		int b=pq.top();//取出第二小元素
		pq.pop();
		ans+=a+b;//合并消耗的能量值累加
		pq.push(a+b);//合并后再放入堆中
	}
	cout<<ans<<endl;//输出
	return 0;//完结撒花！
}