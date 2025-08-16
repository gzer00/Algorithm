//로봇 시뮬레이션
/*
1. 로봇의 위치 및 방향을 저장할 구조체, 땅에 로봇이 있는지 여부와 로봇의 번호를 저장할 벡터에 정보 입력
2. 명령어에 따라 로봇의 방향 회전 또는 해당방향으로 이동
*/

#include <iostream>
#include <vector>

using namespace std;

struct Robot {  //로봇의 정보
    int x, y, dir;  //dir : 북서남동(0~3)
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
     
    int dx[4] = { 0, -1, 0, 1 };    //로봇의 dir값을 인덱스로 이동
    int dy[4] = { 1, 0, -1, 0 };

    int a, b, n, m;     //땅의 열, 행, 로봇의 수, 명령의 수
    cin >> a >> b >> n >> m;

    vector<Robot> robot;    //로봇 정보를 저장할 벡터
    vector<vector<pair<bool, int>>> ground(b, vector<pair<bool, int>>(a, { false, 0 }));    //땅에는 로봇이 있는지 여부와 있을 때의 로봇의 번호를 저장 (없을 때의 로봇의 번호는 0으로 설정)
    for (int i = 0; i < n; i++) {   //로봇의 정보 저장
        int x, y;
        char dir;
        cin >> x >> y >> dir;
        if (dir == 'N')
            robot.push_back({ x, y, 0 });
        else if (dir == 'W')
            robot.push_back({ x, y, 1 });
        else if (dir == 'S')
            robot.push_back({ x, y, 2 });
        else if (dir == 'E')
            robot.push_back({ x, y, 3 });
        ground[y - 1][x - 1] = { true, i + 1 };     //땅에 로봇의 번호 저장
    }
    
    for (int i = 0; i < m; i++) {   //명령어 수행
        int nRobot, count;  //로봇의 번호, 명령 수행 횟수
        char simul;     //명령어
        cin >> nRobot >> simul >> count;
        if (simul == 'L')   //좌회전 (dir + 1)
            for (int j = 0; j < count; j++) {
                if (robot[nRobot - 1].dir == 3)
                    robot[nRobot - 1].dir = 0;
                else
                    robot[nRobot - 1].dir++;
            }
        else if (simul == 'R')  //우회전 (dir - 1)
            for (int j = 0; j < count; j++) {
                if (robot[nRobot - 1].dir == 0)
                    robot[nRobot - 1].dir = 3;
                else
                    robot[nRobot - 1].dir--;
            }
        else if (simul == 'F') {    //dir 방향대로 이동
            int ndir = robot[nRobot - 1].dir;   //현재 로봇의 방향
            int ny = robot[nRobot - 1].y - 1, nx = robot[nRobot - 1].x - 1;     //현재 로봇의 위치
            ground[ny][nx] = { false, 0 };  //이동 전 위치를 초기화
            for (int j = 0; j < count; j++) {
                if (ny + dy[ndir] < 0 || ny + dy[ndir] >= b || nx + dx[ndir] < 0 || nx + dx[ndir] >= a) {   //땅의 범위를 벗어나는 경우
                    cout << "Robot " << nRobot << " crashes into the wall\n";
                    return 0;
                }
                if (ground[ny + dy[ndir]][nx + dx[ndir]].first) {   //다른 로봇이 있는 위치로 이동한 경우
                    cout << "Robot " << nRobot << " crashes into robot " << ground[ny + dy[ndir]][nx + dx[ndir]].second << "\n";
                    return 0;
                }
                ny += dy[ndir];     //현재 위치 정보 저장
                nx += dx[ndir];
            }
            ground[ny][nx] = { true, nRobot };  //현재 위치 정보 땅에 저장
            robot[nRobot - 1].y = ny + 1;   //로봇 구조체의 정보 변경
            robot[nRobot - 1].x = nx + 1;
        }
    }
    cout << "OK\n";
}
