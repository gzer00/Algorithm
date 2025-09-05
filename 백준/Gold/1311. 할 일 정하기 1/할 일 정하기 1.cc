#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> d, dp;

int dfs(int person, int mask) {
	if (person == n)	//모든 사람을 선택한 경우
		return 0;
	if (dp[person][mask] != 987654321)
		return dp[person][mask];
	for (int i = 0; i < n; i++)
		if (!(mask & 1 << i))
			dp[person][mask] = min(dp[person][mask], dfs(person + 1, mask | (1 << i)) + d[person][i]);
	return dp[person][mask];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	d = vector<vector<int>>(n, vector<int>(n));
	dp = vector<vector<int>>(n, vector<int>(1<<n, 987654321));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> d[i][j];
	cout << dfs(0, 0) << "\n";
	return 0;
}