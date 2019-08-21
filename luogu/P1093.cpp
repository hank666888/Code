#include<iostream>
#include<algorithm>
using namespace std;

struct Student{
    int Chinese,English,math;
    int sum,index;
}student[310] ;

bool cmp(Student a,Student b){
    if(a.sum!=b.sum)
        return a.sum>b.sum;
    if(a.Chinese!=b.Chinese)
        return a.Chinese>b.Chinese;
    return a.index<b.index;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>student[i].Chinese>>student[i].English>>student[i].math;
        student[i].index=i;
        student[i].sum=student[i].Chinese+student[i].English+student[i].math;
    }
    sort(student+1,student+1+n,cmp);
    for(int i=1;i<=5;i++)
        cout<<student[i].index<<" "<<student[i].sum<<endl;
    return 0;
}
