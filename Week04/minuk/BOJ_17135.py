# """
# 범위를 어떻게 하지? 일단 좌표 3개 고르는거는 할 수 있을 것 같음..!
# 1이면 bfs를 한번하고
# 2면 bfs를 한번한 뒤 각 좌표에 대해 한번씩 더 총 5번
# 하.. 궁수는 성에 있구나,,
# """

# # 한번씩 돌고, 있으면 break 없으면 한번 더
# # 있을 경우 sort해서 가장 왼쪽

# import sys
# from collections import deque
# input = sys.stdin.readline

# dx = [1, -1, 0, 0]
# dy = [0, 0, 1, -1]

# def bfs(temp, tenemy):
#     # temp는 궁수 좌표 3개, tenemy는 적 좌표 set
#     temp_q = deque([deque([]) for _ in range(3)]) # 궁수 3명이니까 한번 할때마다 각각 해야돼
#     for i in range(3):
#         temp_q[i].append(temp[i])
    
#     kill_cnt = 0
#     visited = [[[0] * 3 for _ in range(n)] for _ in range(m)] # 방문기록
#     while tenemy:
#         for archer in range(3):
#             for _ in range(d):
#             # d 즉, 공격 거리만큼 반복
#                 q = deque(temp_q[archer])
#                 kill_enemy = [] # 궁수가 죽인 적 배열
#                 while q:
#                     x, y = q.popleft()
#                     for i in range(4):
#                         nx = x + dx[i]
#                         ny = y + dy[i]
#                         if 0 <= nx < n and 0 <= ny < m and not visited[ny][nx][archer]:
#                             visited[ny][nx][archer] = 1
#                             temp_q[archer].append((nx, ny))
#                             if (nx, ny) in tenemy:
#                                 kill_enemy.append((nx, ny))
#                 if kill_enemy:
#                     kill_enemy.sort()
#                     kill_cnt += 1
#                     tenemy.remove(kill_enemy[0])
#                     continue
                
#             to_remove = set()
#             to_add = set()

#             for x, y in tenemy:
#                 y += 1
#                 if y != m:
#                     to_add.add((x, y))
#                 to_remove.add((x, y-1))

#             tenemy -= to_remove
#             tenemy |= to_add

            
#     return kill_cnt

# def dfs(idx, cnt):
#     # 백트래킹
#     global result
#     if cnt == 3:
#         tenemy = set(enemy) # 시뮬레이션 돌릴 잠깐 쓸 적 set
#         result = max(result, bfs(temp, tenemy))
#         return 

#     for i in range(idx, len(archer)):
#         temp.append(archer[i])
#         dfs(i+1, cnt+1)
#         temp.pop()
    
# n, m, d = map(int, input().split())

# graph = [list(map(int, input().split())) for _ in range(m)]
# archer = [(x, m) for x in range(n)] # 궁수 좌표
# enemy = set([]) # 적 좌표
# result = 0 # 적 처치 개수

# # 궁수 좌표 및 적 좌표 저장
# for y in range(m):
#     for x in range(n):
#         if graph[y][x] == 1:
#             enemy.add((x, y))

# temp = [] # 궁수 좌표 3개 뽑은 배열
# dfs(0, 0)
# print(result)

"""
처음부터 다시 설계하기 !
n개의 행 (y가 n까지) m개의 열 (x가 m까지)
궁수는 인덱스로 y=n인 부분에서 0~(m-1)까지 중 3개를 뽑아서 씀. 일단 이 좌표를 뽑기
그 다음 범위에 따른 bfs로 ? 왼쪽부터 하려고 했는데,,
적을 기준으로 하는게 더 편할 수도? 그냥 맨 왼쪽 적부터 거리계산하기?
d까지니까 n이면 n-d에 있는 친구들이 최대 인덱스
"""

import sys
input = sys.stdin.readline

# 궁수 좌표 3개 고르기
def dfs(idx, cnt):
    if cnt == 3:
        t = []
        for i in range(3):
            t.append((n, temp[i]))
        archer.append(t)
        return
    
    for i in range(idx, m):
        temp.append(i)
        dfs(i+1, cnt+1)
        temp.pop()

n, m, d = map(int, input().split())

# 적 좌표 담기
enemy = []
for y in range(n):
    temp = list(map(int, input().split()))
    for x in range(m):
        if temp[x] == 1:
            enemy.append((x, y))

archer = []
temp = []
dfs(0, 0)

# print(archer)
# [[(5, 0), (5, 1), (5, 2)], [(5, 0), (5, 1), (5, 3)], .. ]
# print(enemy)
# [(0, 3), (1, 3), (2, 3), (3, 3), (4, 3)]