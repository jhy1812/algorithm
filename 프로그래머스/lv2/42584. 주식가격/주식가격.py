from collections import deque

def solution(prices):
    leng = len(prices)
    q = deque()    
    q.append((prices[0], 0))
    answer = [0] * leng
    
    for i in range(1, leng):
        if q[-1][0] > prices[i]:
            while True:
                if len(q) == 0:
                    q.append((prices[i], i))
                    break;
                tmp = q[-1]
                if tmp[0] > prices[i]:
                    answer[tmp[1]] = i - tmp[1]
                    q.pop()
                else:
                    q.append((prices[i], i))
                    break;
        else:
            q.append((prices[i], i))
    
    for i in range(leng):
        if answer[i] == 0:
            answer[i] = leng - i - 1
    
    return answer