# get data from db
data:  
	psql -d hwu -t -A -F"," -c "select * from bcr where subset like '%CSF%';" > data/raw/csf_cdr3.csv
	psql -d hwu -t -A -F"," -c "select * from bcr where subset not like '%CSF%';" > data/raw/pb_cdr3.csv

#6 current run this with make -B force run

# find similar cdr3
run: 
	 python pickle_data.py
	 python distance_cython.py

# generate summary table
summary:
	 perl stat.pl |sort -n > stat_sorted.csv
	 textql --sql 'select a.c0,a.c1,a.c2, b.c5, b.c0,b.c1,b.c2 from stat_sorted a, csf_cdr3 b where a.c2 = b.c3' stat_sorted.csv data/raw/csf_cdr3.csv >summary_h2.csv


.PHONY: data, run, summary
