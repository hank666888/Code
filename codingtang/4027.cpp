#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string a, b;
int m, n, f[2010][2010], k;

int main() {
	cin >> a >> b;
	cin >> k;
	m = a.size(), n = b.size();
	a = ' '+a, b = ' '+b;
	for (int i=1; i<=m; i++)
		f[i][0] = i*k;
	for (int j=1; j<=n; j++)
		f[0][j] = j*k;
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++) {
			f[i][j] = 1e9;
			f[i][j] = min(int(f[i-1][j-1]+abs(a[i] - b[j])), min(f[i-1][j]+k, f[i][j-1]+k));
		}
	cout << f[m][n] << endl;
	return 0;
}