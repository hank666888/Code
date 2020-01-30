#include <iostream>
using namespace std;

long long a[10000010], sum[10000010], ans, ans_l, ans_r;
int n, m;

int find(int l, int right) {
	int left = l+1;
	while (left <= right) {
		int mid = (left+right)/2;
		if (sum[mid] - sum[l-1] > m) right = mid-1;
		else if (sum[mid] - sum[l-1] < m) left = mid+1;
		else return mid;
	}
	return right;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		sum[i] = sum[i-1]+a[i];
	}
	for (int i=1; i<n; i++) {
		int x = find(i, n);
		if (sum[x] - sum[i-1] > ans) {
			ans = sum[x]-sum[i-1];
			ans_l = i;
			ans_r = x;
		}
	}
	cout << ans_l << ' ' << ans_r << ' ' << ans << endl;
	return 0;
}