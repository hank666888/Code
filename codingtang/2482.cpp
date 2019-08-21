#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 10010;

vector<int> G[MAXN], rG[MAXN];

int n, m, col_num, color[MAXN], cnt, vs[MAXN], num[MAXN], cd[MAXN], ans;
bool visited[MAXN];

void dfs(int u) {
	visited[u] = true;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (!visited[v]) dfs(v);
	}
	vs[++cnt] = u;
}

void rdfs(int u, int k) {
	visited[u] = true;
	color[u] = k;
	for (int i = 0; i < rG[u].size(); i++) {
		int v = rG[u][i];
		if (!visited[v]) {
			num[k]++;
			rdfs(v, k);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		rG[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		if (!visited[i]) dfs(i);
	memset(visited, false, sizeof(visited));
	fill(num+1, num+1+n, 1);
	for (int i = cnt; i >= 1; i--) 
		if (!visited[vs[i]]) rdfs(vs[i], ++col_num);
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		for (int j = 0; j < rG[i].size(); j++) {
			int u = rG[i][j];
			if (!visited[color[u]]) {
				visited[color[u]] = true;
				if (color[i] == color[u])
					cd[i] += num[color[u]] - 1;
				else
					cd[i] += num[color[u]];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (cd[i] == n - 1) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}