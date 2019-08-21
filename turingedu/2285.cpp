#include <iostream>
#include <vector>
#include <cstdio>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;

const int mod = 998244353;

int n, m, f[10000010], ans;

void init() {
	for (int i=1; i<=n; i++)
		f[i] = i;
}

int find(int x) {
	if (f[x] != x)
		f[x] = find(f[x]);
	return f[x];
}

void unite(int x, int y) {
	if (find(x) == find(y)) return ;
	x = find(x);
	y = find(y);
	f[y] = x;
}

bool same(int x, int y) {
	return find(x) == find(y);
}

int main() {
	cin >> n >> m;
	init();
	while (m--) {
		int q, u, v;
		scanf("%d", &q);
		scanf("%d%d",&u,&v);
		if (q == 0) unite(u, v);
		else {
			if (same(u, v))
				ans = (ans*2+1) % mod;
			else
				ans = ans*2 % mod;
		}
	}
	cout << ans << endl;
	return 0;
}