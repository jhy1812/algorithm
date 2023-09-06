from collections import deque    

def solution(s):    
    q = deque()
    
    for i in range(len(s)):
        if s[i] == "(":
            q.append(s[i])
        else:
            if len(q) == 0:
                return False
            q.pop()
    if len(q) != 0:
        return False
    return True