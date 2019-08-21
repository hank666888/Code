#include<iostream>
#include<algorithm>
using namespace std;

struct Student{
	int chinese,math,english,index,sum;
};
Student student[310];
bool cmp(Student a,Student b){
	if(a.sum!=b.sum)
		return a.sum>b.sum;
	if(a.chinese!=b.chinese)
		return a.chinese>b.chinese;
	return a.index<b.index;
}
int n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>student[i].chinese>>student[i].math>>student[i].english;
		student[i].index=i;
		student[i].sum=student[i].chinese+student[i].math+student[i].english;
	}
	sort(student+1,student+1+n,cmp);
	for(int i=1;i<=5;i++)
		cout<<student[i].index<<" "<<student[i].sum<<endl;
	return 0; 
} 
