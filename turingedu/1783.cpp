#include <iostream>
using namespace std;

int n, m, mod = 1e9;
int a[10010], f[10010];

int main() {
	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	f[0] = 1;
	for (int i=1; i<=n; i++)
		for (int j=a[i]; j<=m; j++)
			if (f[j-a[i]])
				f[j] = (f[j-a[i]]+f[j]) % mod;
	cout << f[m] << endl;
	return 0;
}