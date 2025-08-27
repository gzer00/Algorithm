# # 완전탐색으로 했는데 시간초과 !

# import sys
# input = sys.stdin.readline

# n, k = map(int, input().split())
# a = list(map(int, input().split()))
# a = [-1] + a
# cnt = 0 # 내구도가 0인 칸 개수
# step = 0 # 단계
# conveyer = [0] * (2*n+1) # 1~2n 0은 안쓸래

# while cnt < k: # k보다 작으면 계속
    
#     # 1단계
#     temp_c = conveyer[2*n]
#     temp_a = a[2*n]
#     for i in range(2*n, 1, -1):
#         conveyer[i] = conveyer[i-1]
#         a[i] = a[i-1]
#     conveyer[1] = temp_c
#     a[1] = temp_a
#     conveyer[n] = 0
    
#     # 2단계
#     for i in range(n-1, 0, -1):
#         if conveyer[i+1] == 0 and conveyer[i] == 1 and a[i+1] > 0:
#             conveyer[i+1] = 1
#             conveyer[i] = 0
#             a[i+1] -= 1
#     conveyer[n] = 0
    
#     # 3단계
#     if conveyer[1] == 0 and a[1] > 0:
#         conveyer[1] = 1
#         a[1] -= 1
    
#     # 4단계
#     cnt = 0
#     for i in range(1, 2*n+1):
#         if a[i] == 0:
#             cnt += 1
#     step += 1

# print(step)

# 어떻게 줄일 수 있을까 ?
# pypy로 하니까 일단 되긴해
# deque로 바꿨는데 시간초과
# 내구도를 그냥 convey로 합치기?
# 로봇? 정보 배열을 담고 그냥 그것만큼 빼면 돼

import sys
from collections import deque
input = sys.stdin.readline

n, k = map(int, input().split())
conveyer = deque(map(int, input().split()))
robot = deque([0] * n) # 로봇
cnt = 0 # 내구도가 0인 칸 개수
step = 0 # 단계


while cnt < k: # k보다 작으면 계속
    step += 1
    
    # 1단계 deque에 rotate 쓰기
    conveyer.rotate(1)
    robot.rotate(1)
    robot[-1] = 0
    
    # 2단계
    for i in range(n-2, -1, -1):
        if robot[i+1] == 0 and robot[i] == 1 and conveyer[i+1] > 0:
            robot[i+1] = 1
            robot[i] = 0
            conveyer[i+1] -= 1
            # 4단계 한번에 여기서는 어짜피 1->0된 경우만
            if conveyer[i+1] == 0:
                cnt += 1
    robot[-1] = 0
    
    # 3단계
    if conveyer[0] > 0:
        robot[0] = 1
        conveyer[0] -= 1
        if conveyer[0] == 0:
            cnt += 1

print(step)