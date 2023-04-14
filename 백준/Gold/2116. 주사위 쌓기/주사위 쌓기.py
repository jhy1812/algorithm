import sys                      # 재귀가 최대 10000회(최대 주사위 수) 일어날 수 있어 
sys.setrecursionlimit(10**6)    # 기본 재귀 제한인 약 1000회에서 1000000회로 늘려줌
input = sys.stdin.readline

def get_top(bt):                # 밑면으로 정한 인덱스를 입력하면
    if bt == 0:                 # 윗면으로 정해지는 면의 인덱스를 반환하는 함수
        return 5                # [1, 2, 3, 2, 3, 1] 형태로 주사위 정보 입력 받음
    elif bt == 1:               # 같은 숫자끼리 마주보는 면
        return 3
    elif bt == 2:
        return 4
    elif bt == 3:
        return 1
    elif bt == 4:
        return 2
    else:
        return 0

def dice_tower(bt, N, sum, level):      # 밑면을 입력 받았을 때 옆면 중 가장 큰 값을 찾아 더해주는 함수
                                        # bt - 밑면에 써진 값, N - 쌓을 주사위 수
                                        # sum - 옆면의 값을 더해줄 변수, level - 현재 몇 번 째 주사위 인지
                                        
    global maxx                         # 옆면 합의 최대값 저장할 전역변수
    bottom = 0                          # 밑면 인덱스 저장할 변수
    top = 0                             # 윗면 인덱스 저장할 변수
    one_max = 0                         # 현재 주사위의 옆면의 최대값 저장할 변수
                                        
    if level == N:                      # 현재 쌓는 주사위가 마지막 주사위일때
        if maxx < sum:                  # 기존에 저장했던 옆면의 합보다 크면 갱신
            maxx = sum
        return                          # 마지막 주사위면 함수 끝
                                        
    for i in range(6):                  
        if bt == dice[level][i]:        
            bottom = i                  # 밑면의 값이 몇 번 인덱스 인지 검사 하여 저장
    top = get_top(bottom)               # 받아온 밑면 인덱스로 윗면 인덱스 저장
                                        
    for i in range(6):                  # 반복문 통해 해당 주사위의 옆면 최대값이 얼만지 저장할 반복문    
        if i == top or i == bottom:     # 밑면, 윗면에 해당하는 인덱스면 다음 반복문 진행
            continue
        if one_max < dice[level][i]:    # 그렇지 않다면 최대값과 비교하여 갱신
            one_max = dice[level][i]
    sum += one_max                      # 받아온 최대값 sum 변수에 더해줌
    dice_tower(dice[level][top], N, sum, level+1)   # 다음 주사위로 진행



N = int(input())    # 주사위 개수
dice = [0]*N        # 주사위 정보 받을 리스트
maxx = 0            # 옆면 최대값 저장할 변수

for i in range(N):
    dice[i] = [*map(int, input().split())]
    
for i in range(6):                      # 첫 주사위의 각 면이 밑면으로 갔을 모든 경우(6가지)에 대해
    dice_tower(dice[0][i], N, 0, 0)     # 주사위 쌓기

print(maxx)