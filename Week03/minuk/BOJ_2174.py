"""

그냥 시뮬레이션 ,,

근데 생각해보니까 그래프가 필요한가?

=> 그냥 좌표값만 변경하면서 벽에 부딛히는지 확인

근데 로봇끼리 부딛히는거 계산이 그래프 있으면 더 편할듯..?

그냥 근데 그냥 근데

"""

import sys
input = sys.stdin.readline

# 이동함수
def move(x, y, dir, rn):
    # NWSE 순
    dx = [0, -1, 0, 1]
    dy = [1, 0, -1, 0]
    d = ['N', 'W', 'S', 'E']
    
    for i in range(4):
        if dir == d[i]:
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < width and 0 <= ny < height:
                if graph[ny][nx] == 0:
                    graph[ny][nx] = graph[y][x]
                    graph[y][x] = 0
                    robot[rn-1][0] = nx
                    robot[rn-1][1] = ny
                else:
                    print('Robot', rn, 'crashes into robot', graph[ny][nx])
                    exit(0)
            else:
                print('Robot', rn, 'crashes into the wall')
                exit(0)

# 가로 세로
width, height = map(int, input().split())

# (width+1) * (height+1)로 받을 수 있지만 좌표값을 받을 때 -1씩 하려고 !
graph = [[0] * width for _ in range(height)]

n, m = map(int, input().split())

# 로봇 정보
robot = []

# 방향 매핑
left = {'N':'W', 'W':'S', 'S':'E', 'E':'N'}
right = {'N':'E', 'E':'S', 'S':'W', 'W':'N'}

for i in range(n):
    x, y, dir = input().split()
    # 좌표값이 1부터 시작하니까 -1씩
    robot.append([int(x)-1, int(y)-1, dir])
    
    # 그래프에 로봇이 있다는 것 로봇 번호로 표시하기
    graph[robot[i][1]][robot[i][0]] = i+1
    
command = [list(input().split()) for _ in range(m)]

for rn, c, iter in command:
    
    for _ in range(int(iter)):
        if c == 'L':
            robot[int(rn)-1][2] = left[robot[int(rn)-1][2]]
        elif c == 'R':
            robot[int(rn)-1][2] = right[robot[int(rn)-1][2]]
        elif c == 'F':
            # n번 째 로봇
            x, y, dir = robot[int(rn)-1]
            move(x, y, dir, int(rn)) # x, y, 방향

print('OK')