#include<bits/stdc++.h>
using namespace std;

int a[5000010], n, k;

int main()
{
    cin >> n >> k;
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    nth_element(a, a+k, a+n);
    cout << a[k] << endl;
    return 0;
}