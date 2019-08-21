#include <iostream>
#include <algorithm>
using namespace std;

int n, ans, f[10010];

struct Speech {
	int st, ed;
}a[10010];
bool cmp(Speech a,Speech b) {
	if (a.st != b.st) return a.st < b.st;
	return a.ed > b.ed;
}

int main() {
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i].st >> a[i].ed;
	sort(a+1, a+1+n, cmp);
	for (int i=1; i<=n; i++) {
		f[i] = a[i].ed-a[i].st;
		for (int j=1; j<i; j++)
			if (a[j].ed <= a[i].st && f[j]+a[i].ed-a[i].st > f[i])
				f[i] = f[j]+a[i].ed-a[i].st;
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
	return 0;
}