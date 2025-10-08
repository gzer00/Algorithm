#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[2] = { 0, 1 };
int dx[2] = { 1, 0 };

int solution(int m, int n, vector<vector<int>> puddles) {
    const int MOD = 1000000007;
    vector<vector<int>> cnt(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    cnt[0][0] = 1;
    for (auto pos : puddles) {
        cnt[pos[1] - 1][pos[0] - 1] = -1;
    }
    q.push({ 0, 0 });
    while (!q.empty()) {
        int ny = q.front().first, nx = q.front().second;
        q.pop();
        for (int i = 0; i < 2; i++) {
            int ty = ny + dy[i], tx = nx + dx[i];
            if (ty >= n || tx >= m) continue;
            if (cnt[ty][tx] == -1) continue;
            if (cnt[ty][tx] == 0 && (ty != n-1 || tx != m-1))
                q.push({ ty, tx });
            cnt[ty][tx] = (cnt[ty][tx] + cnt[ny][nx]) % MOD;
        }
    }
    return cnt[n - 1][m - 1];
}