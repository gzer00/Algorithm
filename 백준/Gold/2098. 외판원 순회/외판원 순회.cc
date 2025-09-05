#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> w, dp;

int dfs(int city, int mask) {	//마지막 방문한 도시, 방문한 도시들의 집합
	if (mask == (1 << n) - 1)	//모두 선택 함!!!
		return (w[city][0] != 0 ? w[city][0] : 1e9);	//갈 수 없는 경우는 1e9로 표시 !! (방문 안한 건 -1)
	if (dp[city][mask] != -1)	//여기의 최단 거리는 이미 구한 거임 ~
		return dp[city][mask];
	dp[city][mask] = 1e9; //최단 거리 구하기 시작할 꺼니까 !!! (방문함을 표시)
	for (int i = 0; i < n; i++)
		if (!(mask & (1 << i)) && w[city][i] != 0)	//city에서 i까지의 이동거리에 i부터 끝까지의 이동거리 더하기
			dp[city][mask] = min(dp[city][mask], dfs(i, mask | (1 << i)) + w[city][i]);
	return dp[city][mask];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	w = vector<vector<int>>(n, vector<int>(n));
	dp = vector<vector<int>>(n, vector<int>(1 << n, -1));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];
	cout << dfs(0, 1) << "\n";
	return 0;
}