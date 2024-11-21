def solve(sum_score, diff_score):
    if (sum_score + diff_score) % 2 != 0 or (sum_score - diff_score) % 2 != 0:
        return -1

    x = (sum_score + diff_score) // 2
    y = (sum_score - diff_score) // 2

    if x < 0 or y < 0:
        return -1

    return (x, y)

s, d = map(int, input().split())

result = solve(s, d)
if result == -1:
    print(-1)
else:
    print(result[0], result[1])