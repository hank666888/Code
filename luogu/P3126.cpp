#include <iostream>
using namespace std;

const int MAXN = 510, mod = 1000000007;

long long n, f[MAXN][MAXN], ans;
char a[MAXN][MAXN];

int main() {
	cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			cin >> a[i][j];
	f[1][1] = 1;
	for (int i=3; i<=n+1; i++)
		for (int j=i-1; j>=1; j--)
			for (int k=i-1; k>=1; k--) {
				if (a[j][i-j] == a[n-i+k+1][n-k+1]) f[j][k] = (f[j][k] + f[j-1][k-1] + f[j-1][k] + f[j][k-1]) % mod;
				else f[j][k] = 0;
			}
	for (int i=1; i<=n; i++) ans = (ans + f[i][i]) % mod;
	if (a[1][1] != a[n][n]) ans = 0;
	cout << ans << endl;
	return 0;
}