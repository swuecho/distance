import pickle

pickle_filepath = './data/raw/pb_cdr3.data'

lines = []
with open('data/raw/pb_cdr3.csv', 'rb') as f:
    lines = f.readlines()
 #store lines to disk
with open(pickle_filepath, 'wb') as pickle_handle:
    pickle.dump(lines, pickle_handle)
