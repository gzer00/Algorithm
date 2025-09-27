#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int foodRank[8] = { 0, 3, 3, 2, 3, 2, 2, 1 };
int sumF[8];	//TCM(7), TC(3), TM(5), CM(6), M(4), C(2), T(1)
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

struct FG {
	int repy, repx, food;
	vector<pair<int, int>> mem;
};

vector<vector<int>> f, b;
vector<vector<bool>> visited, attacked;
vector<FG> fg;
vector<int> idxG;
int n;

bool compare(int i, int j) {
	if (foodRank[fg[i].food] == foodRank[fg[j].food]) {
		if (b[fg[i].repy][fg[i].repx] == b[fg[j].repy][fg[j].repx]) {
			if (fg[i].repy == fg[j].repy)
				return fg[i].repx < fg[j].repx;
			return fg[i].repy < fg[j].repy;
		}
		return b[fg[i].repy][fg[i].repx] > b[fg[j].repy][fg[j].repx];
	}
	return foodRank[fg[i].food] > foodRank[fg[j].food];
}

void findGroup(int y, int x) {	//점심시간 그룹 형성
	FG nfg;		//현재 그룹 정보
	nfg.food = f[y][x];		//현재 그룹의 음식 종류
	int maxB = 0;	//신앙심 최대
	queue <pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;
	while (!q.empty()) {
		int ny = q.front().first, nx = q.front().second;
		nfg.mem.push_back({ ny, nx });		//현재 그룹 멤버에 추가
		if (b[ny][nx] > maxB) {		//신앙심이 더 큰 경우
			maxB = b[ny][nx];
			nfg.repy = ny;
			nfg.repx = nx;
		}
		else if (b[ny][nx] == maxB) {
			if (ny < nfg.repy) {		//신앙심이 같고, y 좌표가 더 작은 경우
				nfg.repy = ny;
				nfg.repx = nx;
			}
			else if (ny == nfg.repy && nx < nfg.repx) {		//신앙심도 y좌표도 같고 x좌표가 더 작은 경우
				nfg.repy = ny;
				nfg.repx = nx;
			}
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (ny + dy[i] >= 0 && ny + dy[i] < n && nx + dx[i] >= 0 && nx + dx[i] < n && f[ny + dy[i]][nx + dx[i]] == nfg.food && !visited[ny + dy[i]][nx + dx[i]]) {
				visited[ny + dy[i]][nx + dx[i]] = true;
				q.push({ ny + dy[i], nx + dx[i] });
			}
		}
	}	//여기까지 그룹 형성
	for (auto pos : nfg.mem) {
		int ny = pos.first, nx = pos.second;
		if (ny == nfg.repy && nx == nfg.repx)	//대표자인 경우
			b[ny][nx] += nfg.mem.size() - 1;
		else		//나머지 그룹원
			b[ny][nx]--;
	}
	fg.push_back(nfg);
}

void spread(int idx) {
	if (attacked[fg[idx].repy][fg[idx].repx])
		return;		//방어상태
	int dir = b[fg[idx].repy][fg[idx].repx] % 4;
	int mSpr = max(0, b[fg[idx].repy][fg[idx].repx] - 1);
	b[fg[idx].repy][fg[idx].repx] = 1;	//전파자의 신앙심 설정
	int ny = fg[idx].repy, nx = fg[idx].repx;
	while (ny + dy[dir] >= 0 && ny + dy[dir] < n && nx + dx[dir] >= 0 && nx + dx[dir] < n && mSpr > 0) {
		if (f[ny + dy[dir]][nx + dx[dir]] != fg[idx].food) {	//음식이 다른 경우
			int ty = ny + dy[dir], tx = nx + dx[dir];
			attacked[ty][tx] = true;
			if (mSpr > b[ty][tx]) {		//강한 전파
				f[ty][tx] = fg[idx].food;
				mSpr = max(0, mSpr - (b[ty][tx]++ + 1));
			}
			else {	//약한 전파
				f[ty][tx] = fg[idx].food | f[ty][tx];
				b[ty][tx] += mSpr;
				mSpr = 0;
				return;
			}
		}
		ny += dy[dir];
		nx += dx[dir];
	}
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	int t;
	cin >> n >> t;
	f.assign(n, vector<int>(n));
	b.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {	//음식 저장
			char ch;
			cin >> ch;
			if (ch == 'M')
				f[i][j] = 4;
			else if (ch == 'C')
				f[i][j] = 2;
			else
				f[i][j] = 1;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> b[i][j];		//초기 신앙심 저장

	for (int day = 0; day < t; day++) {
		visited.assign(n, vector<bool>(n, false));
		attacked.assign(n, vector<bool>(n, false));
		fg.clear();
		idxG.clear();
		for (int i = 0; i < 8; i++)
			sumF[i] = 0;	//여기까지 초기화
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				b[i][j]++;	//아침 시간
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (!visited[i][j])		//점심 시간
					findGroup(i, j);	//그룹형성
			}
		for (int i = 0; i < fg.size(); i++)
			idxG.push_back(i);
		sort(idxG.begin(), idxG.end(), compare);	//전파 순서
		for (int idx : idxG) {
			spread(idx);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				sumF[f[i][j]] += b[i][j];
		cout << sumF[7] << " " << sumF[3] << " " << sumF[5] << " " << sumF[6] << " " << sumF[4] << " " << sumF[2] << " " << sumF[1] << "\n";

	}

	return 0;
}
