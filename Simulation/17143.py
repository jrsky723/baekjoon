import sys
input = sys.stdin.readline

r, c, m = map(int, input().split())
ans = 0
dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]
board = [[0 for col in range(c + 1)] for row in range(r + 1)]
sharks = [[] for i in range(m + 1)]

def Input():
  for i in range(1, m + 1):
    x, y, s, d, z = map(int, input().split())
    sharks[i] = [x, y, s, d - 1, z, i]
    board[x][y] = i

def Fishing(idx):
  global ans
  for x in range(1, r + 1):
    if board[x][idx]:
      ans += sharks[board[x][idx]][4]
      sharks[board[x][idx]] = 0
      board[x][idx] = 0
      break

def MoveShark():
  for shark in sharks:
    if not shark:
      continue
    x, y, s, d, z, idx = shark
    board[x][y] = 0
    
  for i in range(len(sharks)):
    if not sharks[i]:
      continue
    x, y, s, d, z, idx = sharks[i]
    xR, yR = 2*(r-1), 2*(c-1)
    speed = s
    if dx[d]:
      speed %= xR
    elif dy[d]:
      speed %= yR
    while speed > 0:
      nx = x + dx[d]
      ny = y + dy[d]
      if not (0 < nx <= r and 0 < ny <= c):
        if d in [0, 2]:
          d += 1
        elif d in [1, 3]:
          d -= 1
        continue
      else:
        x, y = nx, ny
        speed -= 1

    sharks[i] = [x, y, s, d, z, idx]
    if board[x][y]:
      if sharks[board[x][y]][4] < z:
        sharks[board[x][y]] = 0
        board[x][y] = idx
      else:
        sharks[i] = 0
    else:
        board[x][y] = idx

Input()
for y in range(1, c + 1):
  Fishing(y)
  MoveShark()

print(ans)
