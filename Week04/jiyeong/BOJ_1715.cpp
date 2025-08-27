//카드 정렬하기 (골드 4)
/*
항상 가장 작은 카드 더미 2개 더하기  ->  우선순위 큐 사용
*/


#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> q;	//우선순위 큐(오름차순)
	int n, sum = 0;;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int card;
		cin >> card;
		q.push(card);
	}

	while (q.size() != 1) {		//카드 더미가 1개일 때까지
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		a += b;		//가장 작은 더미 2개 더해서 합계에 더하기
		sum += a;
		q.push(a);
	}

	cout << sum << endl;
}
