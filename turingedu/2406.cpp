#include<iostream>
#include <cstdio>
using namespace std;
const int N=2000002;
long long ans;
int a[N], n, c, cnt[N], x, s[N];
int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }
    for (x = 1; x <= 50000000; x++)
        s[x] = s[x-1] + cnt[x];
    for (x = 1; x <= 50000000; x++) {
        if (x+x < c)
            ans = ans + s[x] - s[c-x];
        if (x+x == c)
            ans = ans + cnt[x] * (cnt[x]-1) / 2;
    }
    cout << ans << endl;
    return 0;
}
