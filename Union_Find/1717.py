import sys  # 내가 만든 함수를 사용하게 해준다
input = sys.stdin.readline  # 시간초과 방지용  ios::sync_with_stdio(0), cintie(0)
sys.setrecursionlimit(10**6)  # 1000이상의 재귀를 사용할 떄 필수, ** : 제곱연산자,
# 10**6을 입력하는 것이 common

n, m = map(int, input().split())

p = [i for i in range(n + 1)]


def find(x):
  if p[x] != x:
    p[x] = find(p[x])
  return p[x]

def union(u, v):
  u = find(u)
  v = find(v)
  if u < v:
    p[v] = u
  else:
    p[u] = v

for _ in range(m):
  o, a, b = map(int, input().split())
  if (o == 0):
    union(a,b)
  elif o == 1:
    if find(a) == find(b):
      print('YES')
    else:
      print('NO')