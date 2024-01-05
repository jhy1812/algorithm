from collections import deque

def solution(bridge_length, weight, truck_weights):
    count = 0
    tw = 0
    sec = 1
    q = deque()

    while True:
        if count >= len(truck_weights):
            sec = max(sec, q[0][1] + bridge_length)
            q.popleft()
            if not q:
                break
        elif not q:
            q.append((truck_weights[count], sec))
            tw += truck_weights[count]
            sec += 1
            count += 1
        else:
            if tw + truck_weights[count] > weight or len(q) >= bridge_length:
                tmp = q[0][0]
                sec = max(sec, q[0][1] + bridge_length)
                tw -= tmp
                q.popleft()
            else:
                q.append((truck_weights[count], sec))
                tw += truck_weights[count]
                count += 1
                sec += 1

    return sec

