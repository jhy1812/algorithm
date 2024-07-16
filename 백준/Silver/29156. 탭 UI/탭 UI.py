import sys
import decimal

input = sys.stdin.read
data = input().split()

N = int(data[0])
hap = [0.0] * (N + 1)
cen = [0.0] * (N + 1)

index = 1
for i in range(1, N + 1):
    tmp = float(data[index])
    index += 1
    hap[i] = hap[i - 1] + tmp
    cen[i] = hap[i - 1] + tmp / 2

L = float(data[index]) / 2
index += 1
Q = int(data[index])
index += 1

results = []
for _ in range(Q):
    tmp = int(data[index])
    index += 1
    if 2 * L >= hap[N]:
        results.append("0.00")
    elif L >= cen[tmp]:
        results.append("0.00")
    elif L >= hap[N] - cen[tmp]:
        position = decimal.Decimal(hap[N] - 2 * L).quantize(decimal.Decimal('0.00'), rounding=decimal.ROUND_DOWN)
        results.append(f"{position:.2f}")
    else:
        position = decimal.Decimal(cen[tmp] - L).quantize(decimal.Decimal('0.00'), rounding=decimal.ROUND_DOWN)
        results.append(f"{position:.2f}")

sys.stdout.write("\n".join(results) + "\n")
