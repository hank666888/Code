#include <iostream>
using namespace std;

int n, k, p, cnt;
bool book[8010];

int main() {
	cin >> n >> k; 
	int c = 0, now = 0;
	while (c < n) {
		cnt = 0;
		while (cnt < k) {
			now++;
			if (now == n+1)
				now = 1;
			if (!book[now])
				cnt++;
		}
		cout << now << " ";
		book[now] = true;
		c++;
	}
	return 0;
	return 0;
}