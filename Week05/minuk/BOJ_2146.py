"""
100 * 100
10,000을 돌면서 bfs로 섬 좌표 저장하기

island = [[(1, 2), (3, 2)], [()], [()]] 이런식으로 되겠지?

좌표끼리의 차를 다 구하면 얼마나 걸려?
너무 오래걸려 ...

좌표로 하지 말고 그냥 1씩 면적 늘려가면서 섬 하나 만나면 break하기 !
1씩 면적을 어떻게 늘려갈까

좌표로 그냥 해도 될듯..?

좌표가 더 오래걸릴듯 !
"""

import sys
from collections import deque
input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# 거리 구하기
def bfs(coor):
  q = deque(coor) # 섬의 좌표들
  bridge = [row[:] for row in graph] # 그래프 깊은복사

  # 기존 섬은 다 2로 바꿈
  for x, y in coor:
    bridge[y][x] = 2

  # 다리 개수
  cnt = 0
  while q:
    # 한 칸씩 한 칸씩 !
    for _ in range(len(q)):
      x, y = q.popleft()
      for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < n:
          # 0이면 다리 놓기
          if bridge[ny][nx] == 0:
            bridge[ny][nx] = 2
            q.append((nx, ny))
          # 1이면 만난거니까 return
          elif bridge[ny][nx] == 1:
            return cnt
    cnt += 1

  return -1

# 일반적인 bfs로 섬 구하기
def searchIsland(x, y):
  q = deque([(x, y)])
  visited[y][x] = 1
  temp = [(x, y)]

  while q:
    x, y = q.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      if 0 <= nx < n and 0 <= ny < n and graph[ny][nx] == 1:
        if not visited[ny][nx]:
          visited[ny][nx] = 1
          q.append((nx, ny))
          temp.append((nx, ny))

  return temp

island = [] # 섬 좌표들 -> 나중에 다리 놓을 때 사용
result = 1e9 # 최솟값 구하기

n = int(input())
visited = [[0] * n for _ in range(n)]
graph = [list(map(int, input().split())) for _ in range(n)]

# 섬 구하기 bfs
for y in range(n):
  for x in range(n):
    if graph[y][x] == 1 and not visited[y][x]:
      island.append(searchIsland(x, y))

# 이제 island에는 [[섬1], [섬2], ..] 이런식으로 저장

# 한칸씩 늘리면서 거리 구하기 bfs
for coor in island:
  result = min(result, bfs(coor))

print(result)