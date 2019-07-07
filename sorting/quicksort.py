def quicksort(array):
    if len(array)<=1:
        return array
    pivot=array[len(array)//2]
    left=[x for x in array if x<pivot]
    middle=[x for x in array if x==pivot]
    right=[x for x in array if x>pivot]
    return quicksort(left)+middle+quicksort(right)
print(quicksort([2,3,1,5,6,7,4,9,0]))