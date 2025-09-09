#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> dp(n+1, 1e9);
	dp[2] = 1;
	dp[5] = 1;
	for (int i = 2; i <= n - 2; i++) {
		if (dp[i] != 1e9) {
			dp[i + 2] = min(dp[i + 2], dp[i] + 1);
			if (i + 5 <= n)
				dp[i + 5] = min(dp[i + 5], dp[i] + 1);
		}
	}
	if (dp[n] == 1e9)
		cout << "-1\n";
	else
		cout << dp[n] << endl;
}