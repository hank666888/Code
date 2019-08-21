#include<iostream>
#include<algorithm>//STL是个好东西
using namespace std;

int n;

int main(){
    cin>>n;//输入
    for(int i=n/2;i>=1;i--){//枚举
        if(__gcd(i,n-i)==1){//如果互质
            cout<<i<<" "<<n-i<<endl;//输出
            break;//因为只求最大的一对，找到后即可跳出循环
        }
    }
    return 0;//完结撒花！
}