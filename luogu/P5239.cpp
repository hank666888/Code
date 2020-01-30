#include <iostream>
using namespace std;

const int mod = 19260817;

int n, m, q, c[1010][1010];

int main() {
	cin >> q;
	for (int i=1; i<=1000; i++)
		for (int j=1; j<=1000; j++)
			c[i][j] = (c[i-1][j-1]+c[i-1][j]+i) % mod;
	while (q--) {
		cin >> m >> n;
		cout << c[n][m] << endl;
	}
	return 0;
}