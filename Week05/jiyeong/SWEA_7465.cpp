//창용 마을 무리의 개수 (D4)
/*
1. 2차원 벡터에 인덱스 번호의 사람 별로 관계를 맺고 있는 사람들의 번호 저장
2. 무리에 포함되지 않은 경우 무리의 수를 1 증가시키고 dfs로 연결되어 있는 사람들 한 무리로 연결
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m, group = 0;	//사람 수, 관계 수, 무리 수
		cin >> n >> m;
		vector<vector<int>> people(n);	//인덱스 별로 관계를 맺고 있는 사람의 인덱스들 저장
		vector<bool> included(n, false);	//무리에 포함하였는지
		stack<int> s;	//dfs를 위해

		for (int i = 0; i < m; i++) {
			int a, b;	//관계를 갖는 사람 둘
			cin >> a >> b;
			people[a-1].push_back(b-1);		//서로의 people 벡터에 저장
			people[b-1].push_back(a-1);
		}

		for (int i = 0; i < n; i++) {
			if (!included[i]) {		//아직 무리에 포함되지 않은 경우
				group++;	//무리 수 증가
				included[i] = true;		//무리에 포함된 것으로 표기
				s.push(i);		//dfs
				while (!s.empty()) {
					int nInd = s.top();
					s.pop();
					for (auto next : people[nInd]) {	//관계를 맺고 있는 사람들과 무리를 연결
						if (!included[next]) {
							included[next] = true;
							s.push(next);
						}
					}
				}
			}
		}
		cout << "#" << test_case << " " << group << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}