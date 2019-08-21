#include <iostream>
#include <stack>
using namespace std;
 
stack<int> stk;
int n, x;
int ans = 0;
char d;

void init() {
    while(!stk.empty()) stk.pop();
}
 
int main() {
    init();
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %c", &x, &d);
        if(stk.empty() && d == 'L') {
            ans++;
            continue;
        }
        if(d == 'R') {
            stk.push(x);
            continue;
        }
        while(!stk.empty()) {
            int top = stk.top();
            if(top > x) {
                break;
            } else {
                stk.pop();
            }
        }
        if(stk.empty()) ans++;
    }
    cout << ans + stk.size() << endl;
    return 0;
}