while True:
        c = int(input().strip())
        if c == 0:
            break
        message = input().strip()
        
        r = len(message) // c
        
        mat = []
        index = 0
        for r in range(r):
            if r % 2 == 0:  
                mat.append(message[index:index + c])
            else:  
                mat.append(message[index:index + c][::-1])
            index += c
        

        result = ''.join(''.join(row[col] for row in mat) for col in range(c))
        
        
        print(result)