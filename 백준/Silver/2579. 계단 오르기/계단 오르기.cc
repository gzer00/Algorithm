#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stairs, dp;

int dfs(int ind) {
	if (ind <= 2 || dp[ind] != 0)
		return dp[ind];
	dp[ind] = max(dfs(ind-2) + stairs[ind], dfs(ind - 3) + stairs[ind - 1] + stairs[ind]);
	return dp[ind];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	stairs = vector<int>(n + 1);
	dp = vector<int>(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> stairs[i];
	if (n >= 1)
		dp[1] = stairs[1];
	if (n >= 2)
		dp[2] = stairs[2] + stairs[1];
	cout << dfs(n) <<endl;
}