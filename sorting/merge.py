def merge(array):
    if len(array)<2:
        return array
    mid=int(len(array)/2)
    left=merge(array[:mid])
    right=merge(array[mid:])
    i,j,ans=0,0,[]
    while i<len(left) and j<len(right):
        if left[i]<right[j]:
            ans.append(left[i])
            i+=1
        else:
            ans.append(right[j])
            j+=1
    ans=ans+right[j:]
    ans=ans+left[i:]
    return ans
a=[1,3,2]
print(merge(a))
san=merge(a)
if len(san)%2!=0:
    print(san[(len(san))/2])
else:
    print((san[len(san)/2]+san[len(san)/2-1])/2)
