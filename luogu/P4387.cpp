#include <iostream>
#include <stack>
using namespace std;

int a[100010], b[100010], q, n, cur = 1;//这里的cur是用来记录当前出栈序列的应出栈元素的编号
stack<int> s;

int main() {
	cin >> q;
	while (q--) {
		cin >> n;
		for (int i=1; i<=n; i++) cin >> a[i];
		for (int i=1; i<=n; i++) cin >> b[i];
		for (int i=1; i<=n; i++) {
			s.push(a[i]);//依次入栈
			while (!s.empty()) {
				if (s.top() == b[cur]) {//符合出栈条件
					s.pop();
					cur++;//记得，该元素出栈后，下一个元素还要出栈，需要后移下标
				}
				else break;//如果不是，那就不要再循环了，否则会死循环
			}
		}
		if (cur > n) cout << "Yes\n";//cur>n表明出栈序列的每个元素都已遍历，即都已出栈（准确说是cur==n+1）
		else cout << "No\n";
		cur = 1;//记得初始化
		while (!s.empty()) s.pop();//记得清空栈
	}
	return 0;//完结撒花！
}