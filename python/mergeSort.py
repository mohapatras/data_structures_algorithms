def merge(A, l, m , r):
    nL = m - l + 1
    nR = r - m
    L = [0] * (nL)
    R = [0] * (nR)

    for i in range(0,nL):
        L[i] = A[l + i]
    for j in range(0, nR):
        R[j] = A[m + 1 + j]
    i=0
    j=0
    k = l

    while i < nL and j < nR :
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1    
        else:
            A[k] = R[j]
            j += 1
        k += 1
    
    while i < nL:
        A[k] = L[i]
        i += 1
        k += 1
    while j < nR:
        A[k] = R[j]
        j += 1
        k += 1
    

def mergeSort(A, l, r):

    if l < r:

        mid = (l + (r - 1)) // 2

        mergeSort(A, l, mid)
        mergeSort(A, mid+1, r)
        merge(A,l, mid, r)

if __name__=="__main__":

    A = [1,8,3,5,2]
    r = len(A)

    for i in range(r):
        print ("%d" %A[i])

    mergeSort(A,0,r-1)

    print ("\n\nSorted array is")

    for i in range(r):
        print ("%d" %A[i])
