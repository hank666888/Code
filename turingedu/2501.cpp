#include <iostream>
using namespace std;

int n, a[110], sum, ans;
bool f[10010];

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	f[0] = true;
	for (int i=1; i<=n; i++)
		for (int j=sum; j>=a[i]; j--)
			if (f[j-a[i]])
				f[j] = true;
	for (int i=1; i<=sum; i++)
		if (f[i]) ans++;
	cout << ans << endl;
	return 0; 
}