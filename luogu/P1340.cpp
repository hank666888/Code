#include <iostream>
#include <algorithm>
using namespace std;

struct edge {
    int u, v, c;
};
bool cmp(edge a, edge b) {
    return a.c < b.c;
}
edge es[1000010];

int n, m, w, fa[200010];

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

bool same(int x, int y){
    return find(x) == find(y);
}

int kruskal(edge in) {
    init();
    int k, ret = 0;
    edge t1, t2;
    for (int i = 1; i <= m; i++)
        if (in.c >= es[i-1].c && in.c <= es[i].c) {
            t2 = es[i];
            es[i] = in;
            k = i;
            break;
        }
    for (int i = k+1; i <= m; i++)
        t1 = es[i], es[i] = t2, t2 = t1;
    for (int i = 1; i <= m; i++)
        if (!same(es[i].u, es[i].v)){
            unite(es[i].u, es[i].v);
            ret += es[i].c;
        }
    return ret;
}

int main() {
    cin >> n >> w;
    for (int i = 1; i <= w; i++){
        int u, v, c;
        cin >> u >> v >> c;
        if (i <= n-1) {
            cout << -1 << endl;
            es[++m] = (edge){u, v, c};
        }
        else {
            if (i == n)
                sort(es+1, es+1+m, cmp);
            m++;
            cout << kruskal((edge){u,v,c}) << endl;
        }
    }
    return 0;
}
