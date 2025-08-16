//안전 영역 (실버 1)
/*
1. 물의 높이를 1~100까지 반복 (ALL flag를 통해 모두 잠기면 반복문 탈출)
2. 반복문 내에서 안전 지역 배열에 저장
3. 안전 지역을 순회하며 dfs(stack)를 통해 안전 지역의 개수 카운팅팅
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
     
    int n, maxR = 1;    //배열의 크기, 안전영역의 최대 개수 *여기서 비가 아예 오지 않는 경우 안전영역의 개수는 1(전체)이므로 초기값을 1로 세팅해야한다.*
    cin >> n;
    vector<vector<int>> region(n, vector<int>(n));  //지역의 배열
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> region[i][j];

    for (int i = 1; i <= 100; i++) {    //물의 높이를 1 이상부터 10이하까지 탐색
        bool ALL = true;    //모두 잠기는 경우를 확인하는 flag
        vector<vector<bool>> water(n, vector<bool>(n, false));  //물에 잠기지 않는 지역은 true
        vector<vector<bool>> visited(n, vector<bool>(n, false));    //dfs 방문 여부
        vector<pair<int, int>> safe;    //안전지역 저장할 벡터

        for (int j = 0 ; j < n ; j++)
            for (int k = 0 ; k < n ; k++)  
                if (region[j][k] > i) {     //안전지역인 경우
                    water[j][k] = true;     //물에 잠기지 않음
                    ALL = false;    //모두 잠기는 것이 아님
                    safe.push_back({ j, k });   //벡터에 저장
                }
        if (ALL)    //모두 잠기는 경우 물의 높이를 더 이상 높이지 않고 반복문 끝냄
            break;

        stack<pair<int, int>> s;    //dfs 스택
        int count = 0;  //현재 물높이의 안전지역의 개수
        for (auto nSafe : safe) {   //안전 지역 탐색
            if (!visited[nSafe.first][nSafe.second]) {  //아직 방문하지 않은 경우
                s.push({ nSafe.first, nSafe.second });
                visited[nSafe.first][nSafe.second] = true;
                count++;    //지역의 개수 저장
                while (!s.empty()) {    //dfs로 연결된 지점 찾음
                    int ny = s.top().first, nx = s.top().second;
                    s.pop();

                    for (int j = 0; j < 4; j++) {
                        if (ny + dy[j] >= 0 && ny + dy[j] < n && nx + dx[j] >= 0 && nx + dx[j] < n && water[ny + dy[j]][nx + dx[j]] && !visited[ny + dy[j]][nx + dx[j]]) {
                            s.push({ ny + dy[j], nx + dx[j] });
                            visited[ny + dy[j]][nx + dx[j]] = true;
                        }
                    }
                }
            }
        }
        if (maxR < count)   //최대값이면 최대로 바꿈
            maxR = count;
    }
    cout << maxR << "\n";
}
