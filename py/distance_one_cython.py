import os
import time
import distance 
from multiprocessing import Pool
import pickle

#python bytes is equal to char* in C
pickle_filepath = './pb_cdr3.data'
lines = []
with open(pickle_filepath, 'rb') as pickle_handle:
    lines = pickle.load(pickle_handle)

def select_item(item, csf_cdr3 ):
    pb_cdr3 = item.split(b',')[3]
    return distance.hamming_distance( csf_cdr3, pb_cdr3, 5)

def process_file(csf_cdr3):
    selected = [ i for i in lines if select_item(i,csf_cdr3) == 1]
    # write into a files nameed by csf_cdr3
    with open('./result/' + csf_cdr3.decode('ascii') + '.csv', 'wb') as f:
        for s in selected:
            f.write(s)

csf_cdr3_lines = []
with open('csf_cdr3.csv', 'rb') as f:
    csf_cdr3_lines = f.readlines()

csf_cdr3 = [ i.split(b',')[3] for i in csf_cdr3_lines]

for i in range(10):
    print(int(time.time()))
    process_file(csf_cdr3[1])
#with Pool(6) as p:
    #p.map(process_file, csf_cdr3[1])

