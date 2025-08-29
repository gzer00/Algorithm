//감시 (골드 3)
/*
1. cctv의 정보(좌표, 종류) 저장
2. dfs로 각 cctv 방향별로 감시하는 영역 저장 후 다음 cctv로 넘기기
3. 모든 cctv를 다 탐색하면 최소 사각지대 찾기
(비효율적이니까 나중에 다시 풀기....)
*/


#include <iostream>
#include <vector>

using namespace std;

int dy[4] = { 0, -1, 0, 1 };	//좌상우하
int dx[4] = { -1, 0, 1, 0 };

struct CCTV {		//cctv 정보(좌표, 감시 방법)
	int y, x, method;
};

int n, m, numC, minC;	//사무실의 크기
vector<CCTV> cctv;	//cctv 모두 저장

void dfs(int index, vector<vector<int>> office) {	//index번째 cctv 방향 정하기
	if (index == numC) {//모든 cctv의 위치 정함
		int count = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (office[i][j] == 0)
					count++;
		if (count < minC)
			minC = count;
		return;
	}

	if (cctv[index].method == 1) {	//1번 종류의 cctv
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> nOffice = office;
			int ny = cctv[index].y, nx = cctv[index].x;
			while (ny + dy[i] >= 0 && ny + dy[i] < n && nx + dx[i] >= 0 && nx + dx[i] < m && nOffice[ny + dy[i]][nx + dx[i]] != 6) {
				nOffice[ny + dy[i]][nx + dx[i]] = 7;
				ny += dy[i];
				nx += dx[i];
			}
			dfs(index + 1,  nOffice);	//4번 dfs 실행
		}
	}
	else if (cctv[index].method == 2) {	//2번 종류의 cctv
		for (int i = 0; i < 2; i++) {	//수평방향, 수직방향
			vector<vector<int>> nOffice = office;
			int ny = cctv[index].y, nx = cctv[index].x;
			while (ny + dy[i] >= 0 && ny + dy[i] < n && nx + dx[i] >= 0 && nx + dx[i] < m && nOffice[ny + dy[i]][nx + dx[i]] != 6) {		//좌(상) 방향
				nOffice[ny + dy[i]][nx + dx[i]] = 7;
				ny += dy[i];
				nx += dx[i];
			}
			ny = cctv[index].y;
			nx = cctv[index].x;
			while (ny + dy[i+2] >= 0 && ny + dy[i + 2] < n && nx + dx[i + 2] >= 0 && nx + dx[i + 2] < m && nOffice[ny + dy[i+2]][nx + dx[i+2]] != 6) {		//우(하) 방향
				nOffice[ny + dy[i + 2]][nx + dx[i + 2]] = 7;
				ny += dy[i + 2];
				nx += dx[i + 2];
			}
			dfs(index + 1, nOffice);	//2번 dfs 실행(수평, 수직)
		}
	}
	else if (cctv[index].method == 3) {		//3번 종류의 cctv
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> nOffice = office;
			for (int j = 0; j < 2; j++) {	//직각방향
				int ny = cctv[index].y, nx = cctv[index].x;
				int dir = (i + j) % 4;
				while (ny + dy[dir] >= 0 && ny + dy[dir] < n && nx + dx[dir] >= 0 && nx + dx[dir] < m && nOffice[ny + dy[dir]][nx + dx[dir]] != 6) {
					nOffice[ny + dy[dir]][nx + dx[dir]] = 7;
					ny += dy[dir];
					nx += dx[dir];
				}
			}
			dfs(index + 1, nOffice);	//4번 dfs 실행
		}
	}
	else if (cctv[index].method == 4) {		//4번 종류의 cctv
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> nOffice = office;
			for (int j = 0; j < 3; j++) {		//3가지 방향
				int ny = cctv[index].y, nx = cctv[index].x;
				int dir = (i + j) % 4;
				while (ny + dy[dir] >= 0 && ny + dy[dir] < n && nx + dx[dir] >= 0 && nx + dx[dir] < m && nOffice[ny + dy[dir]][nx + dx[dir]] != 6) {
					nOffice[ny + dy[dir]][nx + dx[dir]] = 7;
					ny += dy[dir];
					nx += dx[dir];
				}
			}
			dfs(index + 1, nOffice);	//dfs 
		}
	}
	else if (cctv[index].method == 5) {		//5번 종류의 cctv
		vector<vector<int>> nOffice = office;
		for (int i = 0; i < 4; i++) {	//모든 방향으로
			int ny = cctv[index].y, nx = cctv[index].x;
			while (ny + dy[i] >= 0 && ny + dy[i] < n && nx + dx[i] >= 0 && nx + dx[i] < m && nOffice[ny + dy[i]][nx + dx[i]] != 6) {
				nOffice[ny + dy[i]][nx + dx[i]] = 7;
				ny += dy[i];
				nx += dx[i];
			}
		}
		dfs(index + 1, nOffice);	//dfs 한번 실행
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	vector<vector<int>> office(n, vector<int>(m));		//사무실 벡터	
	minC = n * m;	//사각지대의 최소 크기
	for (int i = 0 ; i < n ; i++) 
		for (int j = 0; j < m; j++) {
			cin >> office[i][j];
			if (office[i][j] > 0 && office[i][j] < 6)
				cctv.push_back({ i, j, office[i][j] });		//cctv 정보 저장
		}
	numC = (int)cctv.size();	//cctv수 (모든 cctv의 방향을 정하면 종료

	dfs(0, office);	//0번째 cctv부터 방향 정하기

	cout << minC << endl;
}
