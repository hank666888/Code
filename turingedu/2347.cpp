#include <iostream>
using namespace std;

int n, a[100010], c[100010], sum, ans;
bool f[1000010];

int main() {
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++) {
		cin >> c[i];
		sum += a[i]*c[i];
	}
	f[0] = true;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=c[i]; j++)
			for (int k=sum; k>=j*a[i]; k--)
				if (f[k-j*a[i]]) f[k] = true;
	for (int i=1; i<=sum; i++) 
		if (f[i]) ans++;
	cout << ans << endl;
	return 0;
}