import os
import time
import distance 
from multiprocessing import Pool
import pickle

pickle_filepath = './pb_cdr3.data'
lines = []
with open(pickle_filepath, 'rb') as pickle_handle:
    lines = pickle.load(pickle_handle)

def select_item(item, csf_cdr3 ):
    F = item.split(',');
    pb_cdr3 = F[3];
    return distance.hamming_distance( csf_cdr3, pb_cdr3, 2);

def process_file(csf_cdr3):
    selected = [ i for i in lines if select_item(i,csf_cdr3) == 1]
    # write into a files nameed by csf_cdr3
    with open('./result/' + csf_cdr3 + '.csv', 'w') as f:
        for s in selected:
            f.write(str(s))

csf_cdr3_lines = []
with open('pb_cdr3.csv', 'r') as f:
    csf_cdr3_lines = f.readlines()

csf_cdr3 = [ i.split(',')[3] for i in csf_cdr3_lines]

with Pool(6) as p:
    p.map(process_file, csf_cdr3[0:100])

