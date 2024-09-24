n = int(input()) 
cases = [int(input()) for _ in range(n)] 

result = 0
st = cases[0]

for i in range(1, n):
    if st <= cases[i]:
        result += cases[i] - st
    else:
        st = cases[i]

print(result)
