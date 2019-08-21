#include <iostream>
using namespace std;

const int INF = 1e9;

int n, a[10010], f[10010];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	fill(f + 1, f + 1 + n, INF);
	f[1] = 0;
	for (int i = 1; i < n; i++) 
		for (int j = 1; j <= a[i]; j++)
			f[i + j] = min(f[i + j], f[i] + 1);
	cout << f[n] << endl;
	return 0;
}