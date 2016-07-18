import os
import time
import distance 
from multiprocessing import Pool
import pickle

import pstats, cProfile

import pyximport
pyximport.install()

import distance 

    
cProfile.runctx("distance.hamming_distance(b'abc', b'abe', 2)", globals(), locals(), "Profile.prof")
s = pstats.Stats("Profile.prof")
s.strip_dirs().sort_stats("time").print_stats()

#for i in range(10):
#    print(int(time.time()))
#    process_file(csf_cdr3[1])
#with Pool(6) as p:
#    p.map(process_file, csf_cdr3)

