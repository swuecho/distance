def hamming_distance(char* a,  char* b, int limit ):
    cdef short len_a
    cdef short mismatch
    len_a = len(a)
    if  len_a != len(b):
        return 0
    mismatch = 0
    cdef short i
    for i in range(len_a): 
        if a[i]!= b[i] :
            mismatch+=1
        if mismatch > limit:
            return 0 
    return 1;

