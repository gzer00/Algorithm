#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

set<int> ants;	//개미집 번호 목록
map<int, int> antsHouse;	//개미집 번호(키) - 개미집 좌표(값)

int antTask(int nMax) {
	int maxT = 0;
	vector<int> nowHouse;	//지금 개미집이 있는 위치들
	set<int> startPos;
	for (int ant : ants)
		nowHouse.push_back(antsHouse[ant]);
	if (nowHouse.empty() || nowHouse.size() == 1)	//개미집이 없거나 1개인 경우
		return 0;
	else if (nMax == 1)	//개미가 1개
		return nowHouse.back() - nowHouse.front();
	int l = 0, r = nowHouse.back() - nowHouse.front();
	while (l < r) {
		int mid = (r + l) / 2;	//한 개미 당 탐색 길이
		//cout << mid << endl;
		int nAnt = 0, preP = 0;
		for (int nowP : nowHouse) {
			if (nAnt == 0 || nowP - preP > mid) {	//지금부터 탐색 시작하는 경우이거나 거리가 탐색 거리를 넘어선 경우
				nAnt++;
				preP = nowP;
			}
		}
		if (nAnt > nMax)	//목표 개미 수보다 많은 개미가 사용됨 -> 탐색 길이를 늘려야함
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}

int main() {
	freopen("input.txt", "r", stdin);
	int qr, cmd, sz = 0, value;
	cin >> qr;
	for (int i = 0; i < qr; i++) {
		cin >> cmd;
		if (cmd == 100) {	//마을 건설
			cin >> sz;
			for (int j = 1; j <= sz; j++) {
				cin >> value;
				ants.insert(j);
				antsHouse[j] = value;
			}
		}
		else if (cmd == 200) {	//개미집 건설
			cin >> value;
			ants.insert(++sz);
			antsHouse[sz] = value;
		}
		else if (cmd == 300) {	//개미집 철거
			cin >> value;
			ants.erase(value);
			antsHouse.erase(value);
		}
		else {	//개미집 정찰
 			cin >> value;
			cout << antTask(value) << "\n";
		}
	}
	return 0;
}
