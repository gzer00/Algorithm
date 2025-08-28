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

# 상 하 우 좌
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def move(x, y, graph, dir):
    nx = x + dx[dir]
    ny = y + dy[dir]
    while 0 <= nx < m and 0 <= ny < n and graph[ny][nx] != 6:
        if graph[ny][nx] == 0:
            graph[ny][nx] = -1
        nx += dx[dir]
        ny += dy[dir]
            
def dfs(idx):
    global result
    if idx == len(cctv_list):
        copy_graph = [row[:] for row in graph] # 임시 그래프 (원본 안건드리기)
        # temp에는 t, (x, y), 방향
        for t, coor, d in temp:
            x, y = coor
            if t == 1: # 0 1 2 3
                move(x, y, copy_graph, d)
            elif t == 2: # 0 2 // 01 23
                    move(x, y, copy_graph, d)
                    move(x, y, copy_graph, d+1)
            elif t == 3: # 0 1 2 3 // 02, 21, 13, 30
                if d == 0 or d == 1:
                    move(x, y, copy_graph, d)
                    move(x, y, copy_graph, d+2)
                elif d == 2:
                    move(x, y, copy_graph, d)
                    move(x, y, copy_graph, d-1)
                else:
                    move(x, y, copy_graph, d)
                    move(x, y, copy_graph, d-3)
            elif t == 4: # 0 1 2 3
                if d == 0 or d == 1:
                    move(x, y, copy_graph, d)
                    move(x, y, copy_graph, d+1)
                    move(x, y, copy_graph, d+2)
                elif d == 2:
                    move(x, y, copy_graph, d)
                    move(x, y, copy_graph, d+1)
                    move(x, y, copy_graph, d-2)
                else:
                    move(x, y, copy_graph, d)
                    move(x, y, copy_graph, d-3)
                    move(x, y, copy_graph, d-2)
            elif t == 5:
                move(x, y, copy_graph, d)
                move(x, y, copy_graph, d+1)
                move(x, y, copy_graph, d+2)
                move(x, y, copy_graph, d+3) 
                
        cnt = 0
        for y in range(n):
            for x in range(m):
                if copy_graph[y][x] == 0:
                    cnt += 1
        result = min(result, cnt)
        return
    
    t, x, y = cctv_list[idx]
    
    if t == 1:
        for d in range(4):
            temp.append((t, (x, y), d))
            dfs(idx+1)
            temp.pop()
    elif t == 2:
        for d in range(0, 3, 2):
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
result = 1e9

cctv_list = []
for y in range(n):
    for x in range(m):
        if graph[y][x] != 0 and graph[y][x] != 6:
            cctv_list.append((graph[y][x], x, y))

dfs(0)

print(result)