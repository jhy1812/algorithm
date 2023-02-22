A = int(input())
B = int(input())
C = int(input())
bucket = [0]*10
gob = str(A*B*C)

for i in gob:
    bucket[int(i)] += 1
for i in range(10):
    print(bucket[i])