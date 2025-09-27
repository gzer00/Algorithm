//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
//#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int sumSqr[6] = { 0, 1, 5, 14, 30, 55 };
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

struct Status {
	int t, y, x, k;
};

struct compare {
	bool operator()(Status& a, Status& b) {
		return a.t > b.t;
	}
};

vector<vector<char>> grid;
vector<vector<vector<int>>> minT;	//좌표 + 점프력 - 시간

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	grid.assign(n + 1, vector<char>(n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> grid[i][j];
	int query;
	cin >> query;
	for (int q = 0; q < query; q++) {
		int r1, c1, r2, c2;
		int ans = -1;
		minT.assign(n + 1, vector<vector<int>>(n + 1, vector<int>(6, INF)));
		cin >> r1 >> c1 >> r2 >> c2;
		priority_queue<Status, vector<Status>, compare> pq;
		pq.push({ 0, r1, c1, 1 });   //시작점 우선순위 큐에 넣기
		minT[r1][c1][1] = 0;
		while (!pq.empty()) {
			Status s = pq.top();
			pq.pop();
			if (s.y == r2 && s.x == c2) {   //목표점에 도달한 경우
				ans = s.t;
				break;
			}
			if (s.t != minT[s.y][s.x][s.k]) continue;   //이미 정해진 시간 최솟값보다 큰 경우 + 해당 점프력을 이미 탐색한 경우
			for (int i = 0; i < 4; i++) {   //4방향 탐색
				int ny = s.y, nx = s.x;
				for (int j = 0; j < 5; j++) {   //점프력 1부터 5까지
					ny += dy[i];
					nx += dx[i];
					if (ny < 1 || ny > n || nx < 1 || nx > n)   //범위밖인 경우
						break;
					else if (grid[ny][nx] == '#')   //천척이 있는 경우
						break;
					else if (grid[ny][nx] == '.') {      //안전한 돌
						int dist = j + 1;
						int nt = s.t;
						if (dist > s.k) {   //점프력 증가
							nt += sumSqr[dist] - sumSqr[s.k];
						}
						else if (dist < s.k) {   //점프력 감소
							nt++;
						}
						if (nt+1 < minT[ny][nx][dist]) {
							minT[ny][nx][dist] = nt+1;
							pq.push({ nt + 1, ny, nx, dist });
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

