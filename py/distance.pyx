def hamming_distance(char* a,  char* b, short limit ):
    cdef short len_a
    cdef short mismatch = 0
    len_a = len(a)
    if  len_a != <short> len(b):
        return False
    cdef short i
    for i in range(len_a): 
        mismatch+=(a[i]!= b[i])
        if mismatch > limit:
            return False 
    return True;

def select_item(char* item, char* csf_cdr3 ):
    pb_cdr3 = item.split(b',')[3]
    return hamming_distance( csf_cdr3, pb_cdr3, 5)

def select_all_related(char* csf_cdr3, lines):
    return([ i for i in lines if select_item(i,csf_cdr3)])
