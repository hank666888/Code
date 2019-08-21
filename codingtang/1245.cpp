#include <iostream>
#include <algorithm>
using namespace std;

struct juxing {
	int x, y;
};
juxing a[10010];
bool cmp(juxing m, juxing n) {
	return m.x*m.y < n.x*n.y;
}

int n, f[10010], ans;

int main() {
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i].x >> a[i].y;
	sort(a+1, a+1+n, cmp);
	for (int i=1; i<=n; i++) {
		f[i] = 1;
		for (int j=1; j<i; j++) {
			if ( ((a[i].x>a[j].x&&a[i].y>a[j].y) || (a[i].x>a[j].y&&a[i].y>a[j].x)) && f[j]+1>f[i]) {
				f[i] = f[j]+1;
			}
		}
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
	return 0;
}