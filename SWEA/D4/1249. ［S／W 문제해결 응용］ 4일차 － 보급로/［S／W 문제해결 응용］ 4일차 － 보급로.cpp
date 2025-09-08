#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int INF = 1e9;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		vector<vector<int>> grid(n, vector<int>(n));
		vector<vector<int>> dist(n, vector<int>(n, INF));
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++)
				grid[i][j] = s[j]-'0';
		}
		priority_queue<pair<int, pair<int, int>>> q;
		dist[0][0] = grid[0][0];
		q.push({-dist[0][0], { 0, 0 } });
		while (!q.empty()) {
			int ny= q.top().second.first, nx = q.top().second.second, ndis = -q.top().first;
			q.pop();
			if (ny == n - 1 && nx == n - 1)
				break;
			if (ndis != dist[ny][nx])
				continue;
			for (int i = 0; i < 4; i++) {
				if (ny + dy[i] >= 0 && ny + dy[i] < n && nx + dx[i] >= 0 && nx + dx[i] < n && ndis + grid[ny + dy[i]][nx + dx[i]] < dist[ny + dy[i]][nx + dx[i]]) {
					dist[ny + dy[i]][nx + dx[i]] = ndis + grid[ny + dy[i]][nx + dx[i]];
					q.push({ -dist[ny + dy[i]][nx + dx[i]], {ny + dy[i], nx + dx[i]} });
				}
			}
		}

		cout << "#" << test_case << " " << dist[n-1][n-1] << endl;
	}
	return 0;
}