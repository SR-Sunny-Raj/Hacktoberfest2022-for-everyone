"""An institutional broker wants to review their book of customers to see which are most active. 
Given a list of trades by customer name, determine which customers account for at least 5% of the total number of trades. 
Order the list alphabetically ascending by name."""

import os
import math
import random
import re
import sys

def mostActive(customers):
    store=dict()
    res=[]
    for i in customers:
        if i in store:
            store[i]+=1
        else:
            store[i]=1
        for i in store.items():
            if(i[1])/len(customers)*100>=5 or (len(customers)*5)/100>=5:
                res.append(i[0])
    return sorted(res)
if __name__ =='__main__':
    fptr = open(os.environ['OUTPUT_PATH'],'w')
    customers_count=int(input().strip)
    customers=[]
    for _ in range(customers_count):
        customers_item=input()
        customers.append(customers_item)
    result=mostActive(customers)
    fptr.write('\n'.join(result))
    fptr.write('\n')
    fptr.close() 
