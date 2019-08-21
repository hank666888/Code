#include<iostream>
#include <cstdio>
using namespace std;
const int N=2000002;
long long ans;
int a[N], n, c, cnt[N], x;
int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }
    for (x = 1; x <= 10000000; x++) {
        if (c-x > x)
            ans = ans + cnt[x] * cnt[c-x];
        if (c-x == x)
            ans = ans + cnt[x] * (cnt[x]-1) / 2;
    }
    cout << ans << endl;
    return 0;
}
