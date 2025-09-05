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
		int n, m, group = 0;
		cin >> n >> m;
		vector<vector<int>> people(n);
		vector<bool> included(n, false);
		stack<int> s;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			people[a - 1].push_back(b - 1);
			people[b - 1].push_back(a - 1);
		}

		for (int i = 0; i < n; i++) {
			if (!included[i]) {
				group++;
				included[i] = true;
				s.push(i);
				while (!s.empty()) {
					int nInd = s.top();
					s.pop();
					for (auto next : people[nInd]) {
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
	return 0;
}