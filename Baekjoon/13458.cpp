//시험 감독 (브론즈 2)
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, s;
	long int ans = 0;
	cin >> n;  //시험장의 수
	vector<int> room(n);
	for (int i = 0; i < n; i++)
		cin >> room[i];  //각 시험장의 응시자 수
	cin >> m >> s;  //총감독관과 부감독관이 각각 감시할 수 있는 응시자 수
	for (int i = 0; i < n; i++) {
		room[i] -= m;  //총감독관은 1명 있어야함
		ans++;
		if (room[i] <= 0)  //총감독관 1명만 있으면 되는 경우
			continue;  
		else if (room[i] % s == 0)
			ans += room[i] / s;
		else
			ans += room[i] / s + 1;  // 올림하기 위해
	}
	cout << ans;
	return 0;
}
