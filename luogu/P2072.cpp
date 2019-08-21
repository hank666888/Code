#include <iostream>
#include <cstring>
using namespace std;

int n, m, k, a[10010], cnt, ans, sum[1010][1010], f[1010];
bool vis[10010];

int main() {
	cin >> n >> m >> k;
	for (int i=1; i<=n; i++) 
		cin >> a[i];
	for (int i=1; i<=n; i++) {
		cnt = 0;
		memset(vis, false, sizeof(vis));// 一定要清空!
		for (int j=i; j<=n; j++) {
			if (!vis[a[j]]) {
				vis[a[j]] = true;
				cnt++;
			}
			sum[i][j] = cnt;
		}
	}
	cnt = 0;
	memset(vis, false, sizeof(vis));//注意，出来时也要清空！我被坑了好长时间TAT
	for (int i=1; i<=n; i++) {
		if (!vis[a[i]]) {
			vis[a[i]] = true;
			cnt++;
		}
		if (cnt > k) {
			ans++;
			cnt = 1;
			memset(vis, false, sizeof(vis));//记得清空！
			vis[a[i]] = true;
		}
		if (i == n)
			ans++;
	}
	cout << ans << endl;
	f[0] = 0;
	f[1] = 1;//初始化莫忘掉
	for (int i=2; i<=n; i++) {
		f[i] = 1e9;//因为取最小值，所以初值要赋大
		for (int j=1; j<=i; j++) 
			if (sum[j][i] <= k) //而且危险值不能超过k
				f[i] = min(f[i], f[j-1]+sum[j][i]);
	}
	cout << f[n] << endl;
	return 0; //完结撒花！
}