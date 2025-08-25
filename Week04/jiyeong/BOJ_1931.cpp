//회의실 배정 (골드 5)
/*
끝나는 시간 기준으로 정렬.....
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {	//정렬 기준
	if (a.second == b.second)
		return a.first < b.first;	//끝나는 시간 같으면 시작시간 기준으로 정렬
	return a.second < b.second;	//끝나는 시간 기준으로 정렬
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, count = 1;	//회의의 수, 최대 회의 개수
	vector<pair<int, int>> meeting;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		meeting.push_back({ start, end });
	}
	sort(meeting.begin(), meeting.end(), compare);		//회의 정렬
	int end = meeting[0].second;	//제일 빨리 끝나는 회의의 끝나는 시간
	for (int i = 1; i < n; i++) {
		if (end > meeting[i].first)		//지금 회의 끝나기 전에 다음 회의가 시작하는 경우는 패스
			continue;
		count++;
		end = meeting[i].second;
	}
	cout << count << endl;
}
