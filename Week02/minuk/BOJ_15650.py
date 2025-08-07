# 조합

# 방법 1: 재귀적 표현 C(n,r) = C(n-1, r-1) + C(n-1, r)
# 파스칼 삼각형? 선택한 원소를 포함하는 경우: C(n-1, r-1), 포함하지 않는 경우: C(n-1, r)
def comb1(n, r):
    if r == 0:
        for t in temp:
            print(t, end=" ")
        print()
    elif n < r: return # r개를 뽑을 수 없음
    else:
        temp[r-1] = arr[n-1]
        comb1(n-1, r-1) # n번째 원소 포함함
        comb1(n-1, r) # 포함 안함

# 방법 2: 깊이, 시작숫자 (시작숫자에서 depth 하나 늘면, 시작숫자+1부터 시작)
def comb2(k, s):
    if k == m:
        for t in temp:
            print(t, end=" ")
        print()
    else:
        # [1, 2, 3, 4, 5] (n개) 중에서 3개(m개)를 뽑아야 하는데, 시작숫자가 4면 안돼
        # 그래서 5-3 = 2번째 인덱스, 즉 3까지 진행.
        # +k의 의미는 1개를 뽑으면 다음은 2개만 뽑으면 되니까 범위가 늘어남.
        for i in range(s, n-m+k+1, 1):
            temp[k] = arr[i]
            comb2(k+1, i+1)


n, m = map(int, input().split())
arr = [i for i in range(1, n+1)]
temp = [0]*m

# comb1(n, m)
comb2(0, 0)