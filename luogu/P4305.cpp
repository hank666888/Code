#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

int t, n, a[50010];
std::map<int, int> m;
std::vector<int> v;

int main() {
	scanf("%d", &t);
	while (t--) {
		m.clear();
		v.clear();
		scanf("%d", &n);
		for (int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
			m[a[i]]++;
			if (m[a[i]] == 1) v.push_back(a[i]);
		}
		for (int i=0; i<v.size(); i++) cout << v[i] << " ";
		cout << endl;
	}
	return 0;
}