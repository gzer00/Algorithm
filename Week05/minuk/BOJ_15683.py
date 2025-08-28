"""
1번: 한 쪽 방향 -> 4가지 경우
2번: 반대 방향 -> 2가지 경우
3번: 직각 방향 -> 4가지 경우
4번: 3갈래 -> 4가지 경우
5번: 4갈래 -> 1가지 경우

그래프 크기가 크지 않아서 ! 완탐

ex)
[[], [(0, 1), (2, 3)], [(1, 1), (4, 3)], [], [], [(5, 5)]]
각각 for문 돌면서 방향 정하기
1에서 2개 뽑고 2에서 2개 봅고 5에서 1개 뽑고..

어렵다..

챗지피티 씀 ! 뽑는 경우 ,,

"""

import sys
input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def dfs(idx):
    if idx == len(cctv_list):
        # temp에는 t, (x, y), 방향
        for t, coor, d in temp:
            x, y = coor
            if t == 1:
                nx = x + dx[d]
                ny = y + dy[d]
                
                return
            elif t == 2:
                return
            elif t == 3:
                return
            elif t == 4:
                return
            elif t == 5:
                return
        return
    
    t, x, y = cctv_list[idx]
    
    if t == 1:
        for d in range(4):
            temp.append((t, (x, y), d))
            dfs(idx+1)
            temp.pop()
    elif t == 2:
        for d in range(2):
            temp.append((t, (x, y), d))
            dfs(idx+1)
            temp.pop()
    elif t == 3:
        for d in range(4):
            temp.append((t, (x, y), d))
            dfs(idx+1)
            temp.pop()
    elif t == 4:
        for d in range(4):
            temp.append((t, (x, y), d))
            dfs(idx+1)
            temp.pop()
    elif t == 5:
        temp.append((t, (x, y), 0))
        dfs(idx+1)
        temp.pop()

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
temp = []

cctv_list = []
for y in range(n):
    for x in range(m):
        if graph[y][x] != 0 and graph[y][x] != 6:
            cctv_list.append((graph[y][x], x, y))

dfs(0)