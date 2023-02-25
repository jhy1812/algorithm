import sys
input = sys.stdin.readline

T = int(input())
for tc in range(1, T+1):
    cnt = 0
    score = 0
    quiz = list(input())
    for i in quiz:
        if i == 'O':
            cnt += 1
            score += cnt
        else:
            cnt = 0
    print(score)