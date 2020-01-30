#include <iostream>
#include <algorithm>
using namespace std;

struct thing {
	int w, h, id;
};
thing a[5010];
bool cmp(thing a, thing b) {
	return a.w < b.w;
}

int n, w_min, h_min, f[5010], last[5010], ans, ans_id;

void print(int x) {
	if (last[x] != 0) print(last[x]);
	cout << a[x].id << " ";
}

int main() {
	cin >> n >> w_min >> h_min;
	for (int i=1; i<=n; i++) {
		cin >> a[i].w >> a[i].h;
		a[i].id = i;
	}
	sort(a+1, a+1+n, cmp);
	f[0] = -1;
	for (int i=1; i<=n; i++) {
		if (a[i].w <= w_min || a[i].h <= h_min) {
			f[i] = -1;
			continue;
		}
		f[i] = 1;
		for (int j=0; j<i; j++) {
			if (a[i].w > a[j].w && a[i].h > a[j].h && f[i] < f[j]+1) {
				f[i] = f[j]+1;
				last[i] = j; 
			}
		}
	}
	for (int i=1; i<=n; i++)
		if (f[i] > ans) {
			ans = f[i];
			ans_id = i;
		}
	cout << ans << endl;
	if (ans == 0) return 0;
	print(ans_id);
	return 0;
}