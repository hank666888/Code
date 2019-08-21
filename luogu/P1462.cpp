#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1e9, MAXN = 10010;

struct edge {
	int to, cost;
};
vector<edge> G[MAXN];
int d[MAXN], f[MAXN], a[MAXN], n, m, b, ans;
bool exist[MAXN];
queue<int> q;

bool spfa(int x) {
	fill(d+1, d+1+n, INF);
	exist[1] = true;
	q.push(1);
	d[1] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		exist[v] = false;
		for (int i=0; i<G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v]+e.cost && f[e.to] <= x) {
				d[e.to] = d[v]+e.cost;
				if (!exist[e.to]) {
					q.push(e.to);
					exist[e.to] = true;
				}
			}
		}
	}
	if (d[n] <= b)
		return true;
	return false;
}

int main() {
	cin >> n >> m >> b;
	for (int i=1; i<=n; i++) {
		cin >> f[i];
		a[i] = f[i];
	}
	for (int i=1; i<=m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		G[u].push_back(edge{v, c});
		G[v].push_back(edge{u, c});
	}
	sort(a+1, a+1+n);
	int l=1, r=n;
	while(l <= r) {
		int mid = (l+r)/2;
		if (spfa(a[mid])) {
			ans = a[mid];
			r = mid-1;
		}
		else l = mid+1;
	}
	if (ans == 0) cout << "AFK" << endl;
	else cout << ans << endl;
	return 0;
}