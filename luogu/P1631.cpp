#include <iostream>
#include <queue>//STL是个好东西
#include <algorithm>
using namespace std;

struct Note
{
	int id_a,id_b,sum;
	//id_a为当前a序列的元素下表
    //id_b为当前b序列的元素下表
    //sum为何两个元素之和
	bool operator < (const Note& a) const{
		return sum>a.sum;
	}//STL的堆需要重载运算符
};

priority_queue<Note> pq;//小根堆
int n,a[100010],b[100010];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	sort(a+1,a+1+n);//a序列排序
	sort(b+1,b+1+n);//b序列排序
	for(int i=1;i<=n;i++){
		pq.push((Note){i,1,a[i]+b[1]});
	}//往堆里放值
	for(int i=1;i<=n;i++){
		Note now=pq.top();
		pq.pop();
		cout<<now.sum<<" ";
		now.id_b++;
		now.sum=a[now.id_a]+b[now.id_b];
		pq.push(now);
	}//输出+更新堆
	cout<<endl;//强迫症带换行
	return 0;//完结撒花！
}