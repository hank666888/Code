#include <iostream>
using namespace std;

int n, a[1000010];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n % 2 == 0) {
        for (int i = n; i >= 1; i--) {
            if(i % 2 == 0)
                cout << a[i] << " ";
        }
        for (int i = 1; i <= n; i++)
            if(i % 2 != 0)
                cout << a[i] <<" ";
    }
    else {
        for (int i = n; i >= 1; i--) {
            if(i % 2 != 0)
                cout << a[i] << " ";
        }
        for (int i = 1; i <= n; i++)
            if(i % 2 == 0)
                cout << a[i] <<" ";
    }
    return 0;
}
