"""
1번: 한 쪽 방향 -> 4가지 경우
2번: 반대 방향 -> 2가지 경우
3번: 직각 방향 -> 4가지 경우
4번: 3갈래 -> 4가지 경우
5번: 4갈래 -> 1가지 경우

그래프 크기가 크지 않아서 ! 완탐
"""

import sys
input = sys.stdin.readline

def dfs():
    for i in range(1, 6):
        for x, y in cctv[i]:
            if i == 1:
                for num_1 in range(4):
                    return
            elif i == 2:
                for num_2 in range(2):
                    return
            elif i == 3:
                for num_3 in range(4):
                    return
            elif i == 4:
                for num_4 in range(4):
                    return
            elif i == 5:
                return

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
cctv = [[] for _ in range(6)] # cctv 번호 좌표들 저장

for y in range(n):
    for x in range(m):
        if graph[y][x] != 0 and graph[y][x] != 6:
            cctv[graph[y][x]].append((x, y))
            
dfs()