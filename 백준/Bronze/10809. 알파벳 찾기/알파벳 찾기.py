import sys
input = sys.stdin.readline

S = list(input().rstrip())
bucket = [-1]*26

for i in range(len(S)-1, -1, -1):
    bucket[ord(S[i])-97] = i
print(*bucket)