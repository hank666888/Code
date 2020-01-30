#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2510, MAXM = 2510;

struct cow {
	int l, r;
};
cow c[MAXN];
bool cmp1(cow a, cow b) {
	return a.r < b.r;
}

struct sunscreen {
	int x, num;
};
sunscreen s[MAXM];
bool cmp2(sunscreen a, sunscreen b) {
	return a.x < b.x;
} 

int n, m, ans;

int main() {
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> c[i].l >> c[i].r;
	for (int i=1; i<=m; i++) cin >> s[i].x >> s[i].num;
	sort(c+1, c+1+n, cmp1);
	sort(s+1, s+1+m, cmp2);
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=m; j++) 
			if (s[j].x >= c[i].l && s[j].x <= c[i].r && s[j].num) {
				ans++;
				s[j].num--;
				break;
			}
	cout << ans << endl;
	return 0;
}