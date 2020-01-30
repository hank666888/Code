#include <iostream>
#include <cstdio>
using namespace std;

int n, a[300010], cnt;
double sum, ans;

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++) {
		cnt ++;
		if ((double)((sum+a[i])*(sum+a[i])) / cnt < (double)(a[i]*a[i])) {
			cnt = 1;
			sum = a[i];
		}
		else sum += a[i];
		ans = max(ans, sum*sum/cnt);
	}
	printf("%.7lf\n", ans);
	return 0;
}