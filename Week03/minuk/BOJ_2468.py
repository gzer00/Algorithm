"""
그래프 탐색 -> BFS 인접한 노드 먼저 검색

물에 잠긴 부분을 0으로 표시 (높이는 1이상 100 이하의 정수)

graph 탐색하면서 0이 아닌 지점에서 bfs

그래프를 물에 잠기면 0으로 만들고, 안전지역 통째로 !

***
height에 0도 포함
그래프가 다 1이면 비 1내릴때 안전구역 없는데
안내리면 1개 있음.

"""

import sys
input = sys.stdin.readline
from collections import deque

# 상 하 좌 우
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

# bfs
def bfs(x, y, tgraph):
    q = deque([(x, y)])
    tgraph[y][x] = 0
    
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n and tgraph[ny][nx] != 0:
                q.append((nx, ny))
                tgraph[ny][nx] = 0
    
# 그래프 크기 입력 받기
n = int(input())

# 결과값
result = 0

# 그래프 입력 받기
graph = [list(map(int, input().split())) for _ in range(n)]

# 최대 높이-1 까지 물 받기
h = 0
for i in range(n):
    h = max(h, max(graph[i]))

# 루프 돌기

for height in range(h):
    temp = [[0] * n for _ in range(n)] # 높이만큼 쓸 그래프
    cnt = 0 # 영역 개수
    
    # 높이보다 작은 영역은 0
    for y in range(n):
        for x in range(n):
            temp[y][x] = 0 if graph[y][x] <= height else graph[y][x]

    # 높이보다 큰 영역 합치기
    for y in range(n):
        for x in range(n):
            if temp[y][x] != 0:
                bfs(x, y, temp) # 참조가 함수로 전달돼서 저기서 바꿔도 바뀜..!
                cnt += 1
    
    result = max(result, cnt)

print(result)