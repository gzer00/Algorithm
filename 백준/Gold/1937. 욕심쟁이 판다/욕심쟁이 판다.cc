#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int n;
vector<vector<int>> grid, dp;

int dfs(int y, int x) {
	if (dp[y][x] != 0)
		return dp[y][x];
	dp[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny >= 0 && nx >= 0 && ny < n && nx < n && grid[y][x] < grid[ny][nx]) {
			dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
		}
	}
	return dp[y][x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int maxL = 0;
	cin >> n;
	grid = vector<vector<int>>(n, vector<int>(n));
	dp = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> grid[i][j];
	stack<pair<int, pair<int, int>>>s;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			maxL = max(maxL, dfs(i, j));
	cout << maxL << endl;
}