import os
import time
import distance 
from multiprocessing import Pool
import pickle

#python bytes is equal to char* in C
pickle_filepath = './pb_cdr3.data'

with open(pickle_filepath, 'rb') as pickle_handle:
    lines = pickle.load(pickle_handle)

def process_file(csf_cdr3):
    output_name = './result/' + csf_cdr3.decode('ascii') + '.csv'
    #if os.path.exists(output_name):
    #    return

    selected = distance.select_all_related(csf_cdr3,lines) 
    # write into a files nameed by csf_cdr3
    with open(output_name,'wb') as f:
        for s in selected:
            f.write(s)
with open('csf_cdr3.csv', 'rb') as f:
    csf_cdr3_lines = f.readlines()

csf_cdr3 = [ i.split(b',')[3] for i in csf_cdr3_lines]

for i in range(10):
    print(int(time.time()))
    process_file(csf_cdr3[1])

