#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> grid, nGrid;
vector<pair<int, int>> areaV;
unordered_map<int, vector<pair<int, int>>> mInfo;
unordered_map<int, int> area;
int n, q;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1 ,0 };

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

void findMicro() {
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	unordered_set<int> micro;
	mInfo.clear(); //현재 존재하는 미생물(키)의 좌표들(값)
	vector<bool> confirm(q + 1, false); //미생물이 확인되었는지

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (grid[i][j] != 0 && !visited[i][j]) {    //아직 확인하지 않은 미생물 발견
				int nowM = grid[i][j];
				if (confirm[nowM]) {  //이미 이 미생물 무리 확인 -> 이 미생물 삭제
					micro.erase(nowM);
					mInfo.erase(nowM);
					continue;
				}
				mInfo[nowM].push_back({ 0, 0 });
				micro.insert(nowM);
				confirm[nowM] = true;
				queue<pair<int, int>> q;
				q.push({ i,j });
				visited[i][j] = true;
				while (!q.empty()) {
					int ny = q.front().first, nx = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int y = ny + dy[k], x = nx + dx[k];
						if (y >= 0 && y < n && x >= 0 && x < n &&
							grid[y][x] == nowM && !visited[y][x]) {
							q.push({ y, x });
							visited[y][x] = true;
							mInfo[nowM].push_back({ y - i, x - j }); 
						}
					}
				}
				int minDy = 15, minDx = 15;	//모든 미생물을 0에 가깝게 바꾸기
				for (auto &p : mInfo[nowM]) { minDy = min(minDy, p.first); minDx = min(minDx, p.second); }
				for (auto &p : mInfo[nowM]) { p.first -= minDy; p.second -= minDx; }
			}
		}
	areaV.clear();
	area.clear();
	for (int m : micro) {
		areaV.push_back({ m, mInfo[m].size() });
		area[m] = mInfo[m].size();
	}
	sort(areaV.begin(), areaV.end(), compare);    //넓이가 넓은 것부터 미생물 정보 정렬
}

void move(int nM) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			bool wrongPos = false;
			for (auto pos : mInfo[nM]) {
				if (j + pos.second >= n || j + pos.second < 0 || i + pos.first >= n || i + pos.first < 0 ||  nGrid[i + pos.first][j + pos.second] != 0) {
					wrongPos = true;
					break;
				}
			}
			if (!wrongPos) {
				for (auto pos : mInfo[nM])
					nGrid[i + pos.first][j + pos.second] = nM;
				return;
			}
		}



}

int calResult() {
	int result = 0;
	vector<vector<bool>> cal(q + 1, vector<bool>(q + 1, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			int a = nGrid[i][j], b = nGrid[i][j + 1];
			if (a != 0 && b != 0 && a != b && !cal[a][b]) {
				result += area[a] * area[b];
				cal[a][b] = cal[b][a] = true;
			}
			int c = nGrid[j][i], d = nGrid[j + 1][i];
			if (c != 0 && d != 0 && c != d && !cal[c][d]) {
				result += area[c] * area[d];
				cal[c][d] = cal[d][c] = true;
			}
		}
	}
	return result;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int r1, c1, r2, c2;
	cin >> n >> q;
	grid.assign(n, vector<int>(n, 0));
	for (int i = 1; i <= q; i++) {
		nGrid.assign(n, vector<int>(n, 0));
		cin >> r1 >> c1 >> r2 >> c2;
		for (int j = r1; j < r2; j++)
			for (int k = c1; k < c2; k++)
				grid[j][k] = i;     //미생물 투입
		findMicro();    //미생물 크기가 큰것부터 정렬
		for (int j = 0; j < areaV.size(); j++)
			move(areaV[j].first);   //현재 미생물 이동
		cout << calResult() << endl;    //계산 결과 출력


		grid = nGrid;
	}
	return 0;
}

