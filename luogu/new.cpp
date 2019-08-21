#include <cstdio>
#include <iostream>
using namespace std;
#define maxn 411
#define INF 0x3f3f3f3f
int a1[maxn][maxn], a2[maxn][maxn];  //a1和a2分别表示两种交通工具
int n, m;
int d[maxn];
bool vis[maxn];

int dij (int a[maxn][maxn])              //裸的dijkstra，不多解释
{
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
        vis[i] = 0;
    }
    d[1] = 0;
    for (int j = 1; j <= n; j++) {
        int k = -1;
        int Min = INF;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && d[i] < Min) {
                Min = d[i];
                k = i;
            }
        }
        if (k == -1)
            break;
        vis[k] = 1;
        for (int i = 1; i <= n; i++) {
            if (!vis[i])
                d[i] = min (d[i], d[k]+a[k][i]);
        }
    }
    return d[n];
}

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a1[i][j] = a2[i][j] = INF;   //初始化
        }
    }
    int u, v;
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d", &u, &v);
        a1[u][v] = a1[v][u] = 1;         //无向图
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;
            if (a1[i][j] == INF)       //没有公路必然是铁路
                a2[i][j] = 1;
        }
    }
    int ans1 = dij (a1);//跑两遍dijkstra
    int ans2 = dij (a2);
    if (ans1 >= INF || ans2 >= INF)      //如果其中有一种交通工具不能到达或都不能到达终点，输出-1 。
        cout << "-1" << endl;
    else cout << max (ans1, ans2) << endl; //输出最大值
    return 0;
}