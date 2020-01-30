#include <iostream>
using namespace std;

long long s[1010], a[1010], n, t;
long long f[1010];//注意，要开long long

int main() {
	cin >> n >> t;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		s[i] = s[i-1]+a[i];
	}//读入+预处理前缀和
	f[1] = a[1]*n*n;//初始化f[1](与我前文中的初始化本质一样)
	for (int i=2; i<=n; i++) {
		f[i] = f[i-1]+a[i]*n*n;//初始化f[i]
		for (int j=1; j<i; j++)
			if (a[i]+a[j]<=t) f[i] = min(f[i], f[j-1]+(a[i]+a[j])*(s[i]-s[j-1]));//方程求解
	}
	cout << f[n] << endl;//输出答案
	return 0;//完结撒花！
}