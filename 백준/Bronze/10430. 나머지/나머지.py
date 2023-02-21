A, B, C = [*map(int, input().split())]

print(f'{(A+B)%C}')
print(f'{((A%C) + (B%C))%C}')
print(f'{(A*B)%C}')
print(f'{((A%C)*(B%C))%C}')