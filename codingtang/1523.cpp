#include <iostream>
#include <string>
using namespace std;

string a, b;
int n, m, f[5010][5010];

int main() {
	cin >> a >> b;
	m = a.size(), n = b.size();
	a = ' '+a, b = ' '+b;
	for (int i=1; i<=m; i++)
		f[i][0] = i;
	for (int i=1; i<=n; i++)
		f[0][i] = i;
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++) {
			f[i][j] = 1e9;
			if (a[i] == b[j]) f[i][j] = f[i-1][j-1];
			else f[i][j] = min(f[i-1][j-1], min(f[i][j-1], f[i-1][j])) + 1;
		}
	cout << f[m][n] << endl;
	return 0;
}