#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 1e9, mod = 100003, MAXN = 1000010;
vector<int> G[MAXN];
int n, m, d[MAXN], ans[MAXN];
bool exist[MAXN];
queue<int> q;

void spfa(int s) {
	memset(exist, false, sizeof(exist));
	fill(d+1, d+1+n, INF);
	q.push(s);
	d[s] = 0;
	ans[s] = 1;
	exist[s] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		exist[v] = false;
		for (int i = 0; i < G[v].size(); i++) {
			int to = G[v][i];
			if (d[to] > d[v] + 1) {
				d[to] = d[v] + 1;
				ans[to] = ans[v] % mod;
				if (!exist[to]) {
					exist[to] = true;
					q.push(to);
				}
			}
			else if (d[to] == d[v] + 1)
				ans[to] = (ans[v] + ans[to]) % mod;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	spfa(1);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << endl;
	return 0;
}