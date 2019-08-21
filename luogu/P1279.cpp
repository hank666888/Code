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
	a = ' '+a, b = ' '+b;// 因为string下标从零开始，所以利用string加法的特性，开头加空格
	for (int i=1; i<=m; i++)
		f[i][0] = i*k;
	for (int j=1; j<=n; j++)
		f[0][j] = j*k;
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++) {
			f[i][j] = 1e9; // 因为要取最小，所以初值要赋大
			f[i][j] = min(f[i-1][j-1]+abs(a[i] - b[j]), min(f[i-1][j]+k, f[i][j-1]+k));
			//求三者最小值可用min套min
		}
	cout << f[m][n] << endl; 
	return 0; // 完结撒花！
}