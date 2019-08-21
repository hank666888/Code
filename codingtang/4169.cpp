#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

struct point {
    int x, y;
};
point p[1010];
double dis(point a, point b) {
    return sqrt( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) );
}

struct edge {
    int u, v;
    double c;
};
edge es[1010*1010];
bool cmp(edge a, edge b) {
    return a.c < b.c;
}

int n, m, fa[1010], k;
double ans;

void init() {
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int find(int x) {
    if (fa[x] == x)
        return fa[x];
    return fa[x] = find(fa[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return ;
    fa[x] = y;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void kruskal() {
    init();
    sort(es+1, es+1+m, cmp);
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (find(es[i].u) != find(es[i].v)) {
            cnt++;
            unite(es[i].u, es[i].v);
            if (cnt == n-k) {
                ans = es[i].c;
                break;
            }
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) {
                es[++m].u = i;
                es[m].v = j;
                es[m].c = dis(p[i], p[j]);
            }
    kruskal();
    printf ("%.2f\n", ans);
    return 0;
}
