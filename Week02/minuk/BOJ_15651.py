# 중복순열

# 방법 1: 재귀적 알고리즘
def PI1(n, r):
    if r == 0:
        for t in temp:
            print(t, end=" ")
        print()
    else:
        # 맨 뒤를 빼고, 나머지 n개 중에서 순열
        for i in range(n-1, -1, -1):
            arr[i], arr[n-1] = arr[n-1], arr[i]
            temp[r-1] = arr[n-1]
            PI1(n, r-1) # 그냥 순열은 n-1로 중복 허용 X
            arr[i], arr[n-1] = arr[n-1], arr[i]

# 방법 2: 깊이
def PI2(k):
    if k == m:
        for t in temp:
            print(t, end=" ")
        print()
    else:
        for i in range(n):
            temp[k] = arr[i]
            PI2(k+1)


n, m = map(int, input().split())
arr = [i for i in range(1, n+1)]
temp = [0]*m

# PI1(n, m)
PI2(0)