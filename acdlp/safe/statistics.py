#!/usr/bin/python

import sys
import re
import subprocess
import csv

def processfile(src):

  properties=0
  verified_prop=0
  false_prop=0
  inconclusive_prop=0
  timeout_prop=0
  memout_prop=0
  error_prop=0
  sum_runtime=0.0
  sum_peak_memory=0.0
  decisions=0
  propagations=0
  conflicts=0
  conflict_literals=0
  restarts=0

  # temporary variable
  status="Total"
  f_name=""
  func_name=""
  ver_time=0.0
  total_time=0.0
  search_word="processing"
  result=""
   
  file=open(src)
  lines=[line for line in file]
  
  status_file_name = re.compile("Starting to processing") 
  status_decision = re.compile("decisions") 
  status_propagation = re.compile("propagations") 
  status_conflict  = re.compile("conflicts")
  status_conflict_literal = re.compile("conflict literals")
  status_restart = re.compile("restarts")
  status_result = re.compile("VERIFICATION")
  status_time = re.compile("runsolver_walltime")
  
  report_file=open('statistics.csv', 'wb')
  report = csv.writer(report_file, delimiter=',',
     quotechar='|', quoting=csv.QUOTE_MINIMAL)

  report.writerow(['file_name', 'decisions', 'propagations', 'conflicts', 'conflict_literals', 'restarts', 'time']) 

  for line in lines:
    if status_file_name.search(line):
      list_of_words = line.split()
      f_name = list_of_words[list_of_words.index(search_word) + 1] 
    if status_decision.search(line):
      cols=line.split(':')
      str1=cols[1].lstrip()
      dec=str1.split(' ',1)[0]
      ld = int(dec)
      decisions=decisions+ld;
    if status_propagation.search(line):
      cols=line.split(':')
      str1=cols[1].lstrip()
      prop=str1.split(' ',1)[0]
      lp = int(prop)
      propagations=propagations+lp;
    if status_conflict.search(line):
      cols=line.split(':')
      str1=cols[1].lstrip()
      con=str1.split(' ',1)[0]
      lc = int(con)
      conflicts=conflicts+lc
    if status_conflict_literal.search(line):
      cols=line.split(':')
      str1=cols[1].lstrip()
      lit=str1.split(' ',1)[0]
      lct = int(lit)
      conflict_literals=conflict_literals+lct
    if status_restart.search(line):
      cols=line.split(':')
      str1=cols[1].lstrip()
      res=str1.split(' ',1)[0]
      restart = int(res)
      lr = int(res)
      restarts=restarts+lr
    if status_time.search(line):
      cols=line.split(':')
      str1=cols[1].lstrip()
      time=str1.split(' ',1)[0]
      time_val = time
      lr=0
      lc=0
      lct=0
      lp=0
      ld=0
      report.writerow([f_name,dec,prop,con,lit,restart,time_val]) 
    if status_result.search(line):
       reslt = line.lstrip()
  
  report.writerow([status,decisions,propagations,conflicts,conflict_literals,restarts,time]) 
            
processfile("progress.log-acdlp")
