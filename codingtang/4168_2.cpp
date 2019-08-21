#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = (1LL<<31) - 1, MAXN = 1010, INF = 1e9;
int G[MAXN][MAXN], d[MAXN], n, m, list[MAXN];
long long ans = 1;
bool used[MAXN];

bool cmp(int a, int b) {
    return d[a] < d[b];
}

void init() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            G[i][j] = INF;
    for (int i = 1; i <= n; i++) list[i] = i;
}

void dijkstra(int s) {
    fill(d+1, d+1+n, INF);
    memset(used, false, sizeof(used));
    d[s] = 0;
    while(true) {
        int v = -1;
        for (int u = 1; u <= n; u++)
            if (!used[u] && (v == -1 || d[u] < d[v]) )
                v = u;
        if (v == -1) break;
        used[v] = true;
        for (int u = 1; u <= n; u++)
            if (d[v] + G[v][u] < d[u])
                d[u] = G[v][u] + d[v];
    }
}

int main() {
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        G[u][v] = G[v][u] = c;
    }
    dijkstra(1);
    sort(list+1, list+1+n, cmp);
    for (int i = 2; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j < i; j++)
            if (d[list[j]] + G[list[i]][list[j]] == d[list[i]])
                cnt++;
        ans = ans * cnt % mod;
    }
    cout << ans << endl;
    return 0;
}
