import sys
from itertools import permutations
input = sys.stdin.readline

def game(N, lst):
    score = 0
    st = 0
    for i in range(N):      # 입력 받은 이닝 수만큼 진행
        out = 0             # 아웃 카운트
        b1, b2, b3 = 0, 0, 0    # 1루, 2루, 3루(사람있으면 1, 없으면 0)
        while 1:
            if out == 3:        # 아웃카운트 3이면 다음 이닝     
                break
            if inning[i][lst[st]] == 0:     # 아웃이면
                out += 1                    # 아웃카운트 +1
            elif inning[i][lst[st]] == 1:   # 1루타
                score += b3                 # 3루에 사람있으면 +1, 아니면 +0
                b1, b2, b3 = 1, b1, b2
            elif inning[i][lst[st]] == 2:   # 2루타
                score += b2 + b3            # 2루, 3루에 있는 사람수만큼 점수 +
                b1, b2, b3 = 0, 1, b1
            elif inning[i][lst[st]] == 3:   # 3루타
                score += b1 + b2 + b3
                b1, b2, b3 = 0, 0, 1
            else:                           # 홈런
                score += b1 + b2 + b3 + 1
                b1, b2, b3 = 0, 0, 0
            st = (st + 1)%9
    return score

N = int(input())
inning = [0]*N
maxx = 0
visited = [0]*9
for i in range(N):
    inning[i] = [*map(int, input().split())]
for arr in permutations(range(1,9), 8):             # 2번 선수부터 9번 선수까지 순서(순열)
    arr = list(arr[:3]) + [0] + list(arr[3:])       # 4번 타자는 1번 선수로 고정
    maxx = max(game(N, arr), maxx)
print(maxx)