#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 2010, INF = 1e9;

long long n, c, G[MAXN][MAXN], mincost[MAXN];//小心爆long long!
int x[MAXN], y[MAXN];
bool used[MAXN];

long long dist(int x1, int y1, int x2, int y2) {
	int ret = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	return ret >= c ? ret : INF;
}//距离计算公式，注意特判

long long prim() {
	fill(mincost+1, mincost+1+n, INF);
	memset(used, false, sizeof(used));
	long long ret = 0;
	mincost[1] = 0;
	while(true) {
		int v = -1;
		for (int u=1; u<=n; u++)
			if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
		if (v == -1) break;
		used[v] = true;
		ret += mincost[v];
		for (int u=1; u<=n; u++)
			if (mincost[u] > G[v][u] && !used[u]) mincost[u] = G[v][u];
	}
	return ret >= INF ? -1 : ret; // 注意特判
}//prim算法

int main() {
	cin >> n >> c;
	for (int i=1; i<=n; i++)
		cin >> x[i] >> y[i];
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) {
			if (i == j) continue;//小心自环
			G[i][j] = G[j][i] = dist(x[i], y[i], x[j], y[j]);
		}//建图
	cout << prim() << endl;//输出
	return 0;//完结撒花！
}