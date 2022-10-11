#Shree Ganeshaya Namah:


#Merge sort is a sorting algorithm that makes use of the Divide And Conquer concept.
#In this we first split the array upto unit length arrays and then we merge them according to their value order.
#Time complexity for this algorithm is O(N*log(N))
#Space complexity in worst case scenario is O(N*log(N)) But it's arguable for some cases. 
#I would suggest you to refer to this Answer for a more accurate explanation. "https://stackoverflow.com/questions/63577325/why-is-merge-sort-space-complexity-on"

#Let's Start:

#In this function, we merge the arrays together by comparing their values.
def merging(arr1:list,arr2:list)-> list:
    i,j=0,0
    s = []
    while i<len(arr1) and j<len(arr2):
        if arr1[i]<=arr2[j]:
            s.append(arr1[i])
            i += 1
        else:
            s.append(arr2[j])
            j+=1
    if i<len(arr1):
        s += arr1[i:]
    else:
        s+= arr2[j:]
    return s


#In this function, we first divide the array into multiple arrays of unit length using recursion. Then we return the sorted array from the merging function.
def merge(arr: list)-> list:
    if len(arr)<=1:
        return arr
    n = len(arr)//2
    l = merge(arr[:n])
    r = merge(arr[n:])
    return merging(l,r)

 #Here we're calling the function to test its result.
if __name__=="__main__":
    arr = [10,22,19,2,3,5,16,11,20,1,4,5,8]
    print(merge(arr))
