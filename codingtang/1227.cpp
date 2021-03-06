#include <iostream>
#include <string>
#include <cstring>
using namespace std;

long long n, m, f[51][51], num[51][51], t;
string x;

int main() {
	cin >> t;
	while (t--) {
		cin >> x;
		cin >> m;
		m--;
		n = x.size();
		x = ' '+x; 
		for (int i=1; i<=n; i++)
			for (int j=i; j<=n; j++)
				num[i][j] = num[i][j-1]*10+x[j]-'0';
		for (int i=1; i<=n; i++)
			f[i][0] = num[1][i];
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				for (int k=j; k<i; k++)
					f[i][j] = max(f[i][j], f[k][j-1]*num[k+1][i]);
		cout << f[n][m] << endl;
		memset(f, 0, sizeof(f));
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				num[i][j] = 0;
	}
	return 0;
}
