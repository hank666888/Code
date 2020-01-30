#include <iostream>
using namespace std;

const int mod = 1000007;

int n, m, a[110], f[110][110];

int main() {
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> a[i];
	f[0][0] = 1;
	for (int i=1; i<=n; i++)
		for (int j=0; j<=m; j++)
			for (int k=0; k<=a[i]; k++)
				if (j >= k)
					f[i][j] = (f[i][j]+f[i-1][j-k]) % mod;
	cout << f[n][m] << endl;
	return 0;
}