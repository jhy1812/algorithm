N = int(input())

result = 1;

for i in range(1, 6):
    result *= (N - i + 1)
    result //= i
    
print(result)
   