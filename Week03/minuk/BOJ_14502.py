import sys
from collections import deque
input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# 그냥 bfs !
def bfs(x, y, temp):
    q = deque([(x, y)])
    temp[y][x] = 2
    cnt = 1
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < m and 0 <= ny < n and temp[ny][nx] == 0:
                cnt += 1
                temp[ny][nx] = 2
                q.append((nx, ny))
    return cnt

def dfs(idx, cnt):
    global result
    
    # 벽 개수가 3개가 되면
    if cnt == 3:
        # 그래프 얕은 복사
        temp = [row[:] for row in graph]
        
        # 바이러스 퍼지게 하기 !
        for x, y in virus:
            bfs(x, y, temp)
        
        # 0 개수 세기
        safe = 0
        for y in range(n):
            for x in range(m):
                if temp[y][x] == 0:
                    safe += bfs(x, y, temp)
        
        # 최대값 저장
        result = max(result, safe)
        return
    
    # 벽 좌표 조합
    for i in range(idx, l):
        x, y = coor[i]
        graph[y][x] = 1
        dfs(i+1, cnt+1)
        graph[y][x] = 0

# 세로 가로 입력받기
n, m = map(int, input().split())
result = 0

# 그래프 입력받기
graph = [list(map(int, input().split())) for _ in range(n)]

# 그래프에서 0의 좌표들
coor = []

# 그래프에서 2(바이러스)의 좌표들
virus = []

# 0과 2 좌표들 추가하기
for y in range(n):
    for x in range(m):
        if graph[y][x] == 0:
            coor.append((x, y))
        elif graph[y][x] == 2:
            virus.append((x, y))

# 0의 좌표들 (벽 세울 때 사용!)
l = len(coor)
dfs(0, 0)

print(result)