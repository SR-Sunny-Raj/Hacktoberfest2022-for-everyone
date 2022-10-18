def addDigits(num):
    if(num<10):
        return num
    else:        
        sum1=0
        while(num):
            sum1+=num%10
            num=int(num//10)
        if(sum1<10):
            return sum1
        else:
            return addDigits(sum1)    
    

num=1
t=addDigits(num)
print(t)
