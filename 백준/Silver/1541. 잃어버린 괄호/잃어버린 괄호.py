import sys
input = sys.stdin.readline

formul = input().strip().split('-')
result = 0
for i in range(len(formul)):
    a = formul[i].split('+')
    for j in range(len(a)):
        if i == 0:
            result += int(a[j])
        else:
            result -= int(a[j])
print(result)
