def solution(numbers):
    answer = []
    for n in numbers:
        if n % 2 == 0:
            answer.append(n+1)
        else:
            answer.append(n+((n^(n+1))+1)//4)
            
        
        #아래 코드는 시간초과
        # if n % 2 == 0: 
        #     answer.append(n+1)
        #     continue
        
        # numToBin = bin(n)[2:].zfill(32)[::-1]  
        # while True:
        #     count = 0
        #     n += 1
        #     xToBin = bin(n)[2:].zfill(32)[::-1]
        #     for i in range(32):
        #         if int(numToBin[i]) ^ int(xToBin[i]): 
        #             count+=1
        #             if count > 2: break
        #     else :
        #         answer.append(n)
        #         break
        
    return answer


print(solution([1001,337,0,1,333,673,343,221,898,997,121,1015,665,779,891,421,222,256,512,128,100]))
