#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k, minS;
	minS = 1e9;
	cin >> n >> k;
	vector<vector<int>>enemy(n, vector<int>(3));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> enemy[i][j];
	
	for (int i = 0; i < n; i++)
		for (int j = 0 ; j < n ; j++)
			for (int m = 0; m < n; m++) {
				int jinP = enemy[i][0];
				int jinF = enemy[j][1];
				int jinI = enemy[m][2];		//진수의 스탯 정하기
				int cnt = 0;	//진수가 이길 수 있는 병사 수 카운팅
				for (int l = 0; l < n; l++)
					if (jinP >= enemy[l][0] && jinF >= enemy[l][1] && jinI >= enemy[l][2])
						cnt++;
				if (cnt >= k)
					minS = min(minS, jinP + jinF + jinI);
			}
	cout << minS << "\n";
}