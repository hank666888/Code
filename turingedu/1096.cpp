#include <iostream>
using namespace std;

const int mod = 1e9;

int n, a[10010], f[10010];

void init() {
	for (int i=1; i<=30; i++)
		a[i] = 1<<(i-1);
}

int main() {
	init();
	cin >> n;
	f[0] = 1;
	for (int i=1; i<=30; i++) {
		if (a[i] > n)
			break;
		for (int j=a[i]; j<=n; j++)
			f[j] = (f[j]+f[j-a[i]]) % mod;
	}
	cout << f[n]%mod << endl;
	return 0;
}