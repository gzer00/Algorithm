# 중복조합

# 방법 1: 재귀적 알고리즘
def H1(n, r):
    if r == 0:
        for t in temp:
            print(t, end=" ")
        print()
    elif n == 0: return # r개를 뽑을 수 없음
    else:
        temp[r-1] = arr[n-1]
        H1(n, r-1) # n번째 원소 포함하는데, 중복 허용으로 다시 n번째 뽑을건지!
        H1(n-1, r) # 포함 안함
        
# 방법 2: 깊이, 시작숫자
def H2(k, s):
    if k == m:
        for t in temp:
            print(t, end=" ")
        print()
    else:
        for i in range(s, n, 1): # 원래는 n-m+k+1까지,, 중복해서 m개 뽑을 수 있으니까 제한이 없음
            temp[k] = arr[i]
            H2(k+1, i) # 원래는 i+1 (중복 허용 X)
        
n, m = map(int, input().split())
arr = [i for i in range(1, n+1)]
temp = [0]*m

# H1(n, m)
H2(0, 0)