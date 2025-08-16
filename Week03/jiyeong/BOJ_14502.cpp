//연구소 (골드 4)
/*
1. 백트래킹과 dfs를 통해 3개의 벽을 세울 위치를 정함
2. bfs로 바이러스 확산
3. 확산 완료 후 안전지역 카운팅
*/
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
int maxS = 0, n, m;     //안전영역의 최댓값, 배열의 행, 열
vector<pair<int, int>> virus;   //바이러스 위치를 저장할 벡터
vector<vector<int>> map;    //연구소 지도를 저장할 벡터

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int bfs(vector<vector<int>> nmap) {     //bfs로 안전지역 찾음
	int safe = 0;   //안전지역의 수
	for (int i = 0; i < virus.size(); i++) {    //바이러스 벡터 탐색하며 바이러스 확산
		int y = virus[i].first, x = virus[i].second;
		queue<pair<int, int>> q;
		q.push({ y, x });
		while (!q.empty()) {
			int ny = q.front().first, nx = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {   //벽이 없는 경우 이동 후 그 위치를 바이러스로 바꿈
				if (ny + dy[j] >= 0 && ny + dy[j] < n && nx + dx[j] >= 0 && nx + dx[j] < m && nmap[ny + dy[j]][nx + dx[j]] == 0) {
					q.push({ ny + dy[j], nx + dx[j] });
					nmap[ny + dy[j]][nx + dx[j]] = 2;
				}
			}
		}
	}
	for (int i = 0; i < n;i++) //bfs를 마친 후 안전지역의 수 카운팅
		for (int j = 0; j < m; j++)
			if (nmap[i][j] == 0)
				safe++;
	return safe;
}

void dfs(int y, int x, int count) {     //3개의 조합으로 벽을 정함
	if (count == 3) {   //3개를 다 고른 경우
		int safe = bfs(map);    //bfs로 연구소 지도 탐색
		if (maxS < safe)    //bfs 결과를 최대값과 비교
			maxS = safe;
		return;
	}
    //여기서 현재 행과 다음 행부터를 나누는 이유 : 현재 위치 다음 위치부터 탐색하기 위해
	for (int i = x+1 ; i < m ; i++) //현재 행에서 다음 원소부터 백트래킹하며 벽을 정함
		if (map[y][i] == 0) {
			map[y][i] = 1;
			dfs(y, i, count + 1);
			map[y][i] = 0;
		}
	for (int i = y+1; i < n ; i++)  //다음 행부터 백트래킹하며 벽을 정함
		for (int j = 0; j < m ; j++)
			if (map[i][j] == 0) {
				map[i][j] = 1;
				dfs(i, j, count+1);
				map[i][j] = 0;
			}
}

int main() {
	cin >> n >> m;
	map = vector<vector<int>>(n, vector<int>(m));   //연구소 벡터
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)     //바이러스의 위치 저장
				virus.push_back({ i, j });
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			if (map[i][j] == 0) {   //3개의 조합을 뽑아서 벽을 세우기 위해 백트래킹
				map[i][j] = 1;
				dfs(i, j, 1);      //dfs를 통해 벽의 위치를 조합으로 뽑음
				map[i][j] = 0;
			}
	cout << maxS;
	return 0;
}