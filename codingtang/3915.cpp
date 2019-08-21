#include <iostream>
#include <algorithm>
using namespace std;

struct book {
	int st, ed, len;
};
book a[10010];
bool cmp(book x, book y) {
	return x.st < y.st;
}

int f[10010], b[10010], n, ans, res;

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i].st >> a[i].ed;
		a[i].len = a[i].ed - a[i].st;
	}
	sort(a+1, a+1+n, cmp);
	for (int i=1; i<=n; i++) {
		f[i] = a[i].len;
		b[i] = 1;
		for (int j=1; j<i; j++) {
			if (a[i].st == a[j].ed && f[j]+a[i].len > f[i]) {
				f[i] = f[j]+a[i].len;
				b[i] = b[j]+1;
			}
			else if (a[i].st == a[j].ed && f[j]+a[i].len == f[i])
				b[i] = max(b[i], b[j]+1);
		}
		ans = max(ans, f[i]);
	}
	for (int i=1; i<=n; i++)
		if (f[i] == ans)
			res = max(res, b[i]);
	cout << ans+1 << " " << res << endl;
	return 0;
}