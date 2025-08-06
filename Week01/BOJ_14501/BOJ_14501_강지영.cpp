//퇴사 (실버 3)
#include <iostream>
#include <vector>

using namespace std;

vector<int> t(15), p(15);  //상담 완료하는데 걸리는 기간과 받을 수 있는 금액 (최대 15일)
int n, maxP;  //퇴사까지 남은 기간과 최대 받을 수 있는 금액

void consulting(int ind, int money) {
	if (ind + t[ind] > n) {  //더 이상 상담할 수 없는 경우 현재 금액과 최대 금액 비교하고 재귀 끝
		if (maxP < money) {
			maxP = money;
			return;
		}
	}
	money += p[ind];  //현재 금액에 더 하기
	if (ind + t[ind] == n) {  //정확히 퇴사 전날까지 상담하는 경우 비교하고 최대 끝
		if (maxP < money) {
			maxP = money;
			return;
		}
	}
	for (int i = ind + t[ind]; i < n; i++)  //상담 더 할 수 있으면 계속 재귀 ㄱㄱ
		consulting(i, money);
	return;
}

int main() {
	cin >> n;
	maxP = 0;

	for (int i = 0; i < n; i++)
		cin >> t[i] >> p[i];
	for (int i = 0; i < n; i++) {
		consulting(i, 0);  //재귀함수 실행
	}
	cout << maxP;
	return 0;
}
