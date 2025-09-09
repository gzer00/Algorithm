#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp, rgb;

int dfs(int ind, int color) {
	if (dp[ind][color] != 1e9)
		return dp[ind][color];
	for (int i = 0; i < 3; i++) {
		if (i == color)
			continue;
		dp[ind][color] = min(dp[ind][color], dfs(ind - 1, i) + rgb[ind][color]);
	}
	return dp[ind][color];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, minC = 1e9;
	cin >> n;
	dp = vector<vector<int>>(n, vector<int>(3, 1e9));
	rgb = vector<vector<int>>(n, vector<int>(3));
	for (int i = 0; i < n; i++)
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	dp[0] = rgb[0];
	for (int i = 0; i < 3; i++)
		minC = min(minC, dfs(n - 1, i));
	cout << minC << endl;
}