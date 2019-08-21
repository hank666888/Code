#include <iostream>
#include <string>
using namespace std;

int n, m, f[51][11], num[51][51];
string x;

int main() {
	cin >> n >> m;
	cin >> x;
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
	return 0;
}
