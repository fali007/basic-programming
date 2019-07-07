def bubble(q):
    for i in range(len(q)-1):
        for j in range(len(q)-i-1):
            if q[j]>q[j+1]:
                temp=q[j]
                q[j]=q[j+1]
                q[j+1]=temp
    return q
print(bubble([0,3,2,5,9,6,7,1,8]))