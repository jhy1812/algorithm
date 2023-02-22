N = 10000
bucket = [0]*10000
for i in range(1, 9999):
    if bucket[i] == 0:
        dn = i
        while 1:
            for j in str(dn):
                dn += int(j)
            if dn >= 10000:
                break
            bucket[dn] += 1
for i in range(1, 9999):
    if bucket[i] == 0:
        print(i)