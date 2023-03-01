import sys
input = sys.stdin.readline

N = int(input())
cnt = 0
for i in range(N):
    word = list(input().rstrip())
    bucket = [0]*26
    bucket[ord(word[0])-97] = 1
    flag = 0
    for i in range(1, len(word)):
        if bucket[ord(word[i])-97] != 0 and word[i-1] != word[i]:
            flag = 1
            break
        bucket[ord(word[i])-97] = 1
    if flag == 0:
        cnt += 1
print(cnt)