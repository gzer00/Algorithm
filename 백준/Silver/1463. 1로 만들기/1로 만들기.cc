#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> cal(n + 1, 1e9);
	int now = 1;
	cal[now] = 0;
	while (now < n) {
		if (now * 3 <= n)
			cal[now * 3] = min(cal[now * 3], cal[now] + 1);
		if (now * 2 <= n)
			cal[now * 2] = min(cal[now * 2], cal[now] + 1); 
		if (now + 1 <= n)
			cal[now +1] = min(cal[now + 1], cal[now] + 1);
		now++;
	}
	cout << cal[n] << endl;
}