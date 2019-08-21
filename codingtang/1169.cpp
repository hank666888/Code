#include <iostream>
using namespace std;

int n, v, w[10010], c[10010], f[10010];

int main() {
	cin >> v >> n;
	for (int i=1; i<=n; i++)
		cin >> c[i];
	for (int i=1; i<=n; i++)
		cin >> w[i];
	for (int i=1; i<=n; i++)
		for (int j=v; j>=c[i]; j--)
			f[j] = max(f[j], f[j-c[i]]+w[i]);
	cout << f[v] << endl;
	return 0;
}