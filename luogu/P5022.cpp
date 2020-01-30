#include <iostream>
#include <vector>
using namespace std;

const int MAXN - 5010;

struct edge {
	int from, to;
};
edge e[MAXN*MAXN];

int n, m, cnt;
std::vector<int> G[MAXN];

void dfs()

int main() {
	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int u, v;
		G[u].push_back(v);
		G[v].push_back(u);
		e[++cnt].from = u;
		e[cnt].to = v;
	}
	if (n == m) {

	}
}