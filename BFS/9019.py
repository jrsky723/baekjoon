from collections import deque
import sys
input = sys.stdin.readline


def bfs(st, tg):
  vis = [False] * 10000
  q = deque()
  q.append((st, ""))
  vis[st] = True

  while q:
    cur, path = q.popleft()
    if cur == tg:
      print(path)
      return
    for c in ['D', 'S', 'L', 'R']:
      nxt = cur
      if c == 'D':
        nxt = (2 * cur) % 10000
      elif c == 'S':
        nxt = (cur - 1) % 10000
      elif c == 'L':
        nxt = (10*cur+(cur//1000)) % 10000
      else:
        nxt = (cur//10 + 1000*(cur % 10)) % 10000
      if vis[nxt]:
        continue
      q.append((nxt, path + c))
      vis[nxt] = True


for _ in range(int(input())):
  a, b = map(int, input().split())
  bfs(a, b)
