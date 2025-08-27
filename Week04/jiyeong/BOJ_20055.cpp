//컨베이어 벨트 위의 로봇 (골드 5)
/*
1. belt 배열에 내구성과 로봇이 있는지 저장
2. 시작하는 위치, 내리는 위치 변수로 지정
3. 단계마다 회전 + 로봇 내리기 + 이동 + 로봇 내리기 + 로봇 올리기 반복 (내구성이 0인 칸 카운팅하면서)
4. 내구성이 0인 칸이 k개가 되면 끝 !!!
*/

#include <iostream>
#include <vector>

using namespace std;

int n;	//컨베이터 벨트 크기

int nextLoc(int now) {		//다음 위치
	if (now == 0)
		return (2 * n - 1);
	return now-1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k, zero = 0, stage = 0;	//종료 조건, 내구성이 0인 칸의 개수, 지금 단계
	cin >> n >> k;
	int on = 0, off = n - 1;	//로봇을 올리는 위치, 내리는 위치
	
	vector<pair<int, bool>> belt;		//내구성, 로봇이 있는지
	for (int i = 0; i < 2 * n; i++) {
		int strength;
		cin >> strength;
		belt.push_back({ strength, false });
	}
	while (zero < k) {	//내구성이 0인 칸의 수가 k개가 될 때까지 반복
		stage++;	//단계는 1부터
		on = nextLoc(on);	//벨트를 한번 회전
		off = nextLoc(off);
		if (belt[off].second)	//내리는 위치에 로봇이 있으면 내리기
			belt[off].second = false;
		if (on < off) {	// 벨트의 칸 번호가 증가하는 경우 
			for (int i = off - 1; i >= on; i--) {	//올리는 위치와 내리는 위치 사이만 탐색
				if (belt[i].second && !belt[i + 1].second && belt[i + 1].first > 0) {	//다음 위치에 로봇이 없고 내구성이 0 이상인 경우
					belt[i].second = false;
					belt[i + 1].second = true;
					belt[i + 1].first--;
					if (belt[i + 1].first == 0)		//내구성이 0이 되면
						zero++;
				}
			}
		}

		else {		//벨트의 칸 번호가 큰 값에서 작은 값으로 가는 경우
			for (int i = off - 1; i >= 0; i--) {	//0번째 칸부터 내리는 위치까지 
				if (belt[i].second && !belt[i + 1].second && belt[i + 1].first > 0) {	//다음 위치에 로봇이 없고 내구성이 0 이상인 경우
					belt[i].second = false;
					belt[i + 1].second = true;
					belt[i + 1].first--;
					if (belt[i + 1].first == 0)
						zero++;
				}
			}
			if (belt[2 * n - 1].second && !belt[0].second && belt[0].first > 0) {	//2*n-1번째 칸에서 0번째 칸으로 가는 경우
				belt[2 * n - 1].second = false;
				belt[0].second = true;
				belt[0].first--;
				if (belt[0].first == 0)
					zero++;
			}
			for (int i = 2*n-2; i >= on; i--) {		//
				if (belt[i].second && !belt[i + 1].second && belt[i + 1].first > 0) {	//올리는 위치부터 2*n-1번째 칸까지
					belt[i].second = false;
					belt[i + 1].second = true;
					belt[i + 1].first--;
					if (belt[i + 1].first == 0)
						zero++;
				}
			}
		}
		if (belt[off].second)	//내리는 위치에 로봇이 있으면 내리기 (이동했으니까 한번 더!)
			belt[off].second = false;
		if (belt[on].first > 0 && !belt[on].second) {	//올리는 위치에 로봇이 없고 내구성이 0보다 크면 로봇 올리기 !!
			belt[on].first--;
			belt[on].second = true;
			if (belt[on].first == 0)
				zero++;
		}
	}

	cout << stage << endl;;
}