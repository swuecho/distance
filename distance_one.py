def hamming_distance( a, b, limit ):
    len_a = len(a);
    if  len_a != len(b):
        return 0
    mismatch = 0
    for i in range(len_a): 
        if a[i]!= b[i] :
            mismatch+=1
        if mismatch > limit:
            return 0 
    return 1;

def select_item(item, csf_cdr3 ):
    F = item.split(',');
    pb_cdr3 = F[3];
    return hamming_distance( csf_cdr3, pb_cdr3, 5 );

def process_file(csf_cdr3):
    lines = []
    with open('pb_cdr3.csv') as f:
        lines = f.readlines()
    selected = [ i for i in lines if select_item(i,csf_cdr3) == 1]
    print(selected)
    print(len(selected))

csf_cdr3 = 'CARLDYYYYYGMDL';
process_file(csf_cdr3);
