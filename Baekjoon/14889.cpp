//스타트와 링크 (실버 1)
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main() {

	int n;  //사람 수
	cin >> n;
	vector<vector<int>> ability(n, vector<int>(n));  //능력치표
	vector<bool> team(n / 2, false);  //true면 스타트, false면 링크
	team.insert(team.end(), n / 2, true);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ability[i][j];
		}
	}
	int mind = numeric_limits<int>::max();  //두 팀 능력치 차이의 최솟값
	do {  //team 벡터를 중복없는 순열을 통해 조합을 만들어서 팀 나눔 
		vector<int> start, link;  //스타트팀과 링크팀
		for (int i = 0; i < n; i++) {
			if (team[i])  //true면 스타트팀
				start.push_back(i);
			else
				link.push_back(i);
		}
		int ssum = 0, lsum = 0;  //스타트팀 합과 링크팀 합
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i != j) {
					ssum += ability[start[i]][start[j]];
					lsum += ability[link[i]][link[j]];
				}
			}
		}
		if (mind > abs(ssum - lsum))  //차이의 절댓값과 최솟값 비교
			mind = abs(ssum - lsum);
	} while (next_permutation(team.begin(), team.end()));  //team 벡터의 중복 없는 조합을 만듦
	cout << mind;
	return 0;
}
/*
같은 팀이 스타트팀, 링크팀 두번 반복되어서 비효율적...
dfs로 ㄱㄱ
*/
