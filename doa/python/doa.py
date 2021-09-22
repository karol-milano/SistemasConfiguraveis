#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import re
import csv
import json
import math
import time
import locale

from dateutil.parser import *

from pyexcel_ods3 import save_data
from collections import OrderedDict

from datetime import datetime, timezone

from autor import Autor
from commit import Commit
from variability import Variability

is_ln = True
toCsv = True

locale.setlocale(locale.LC_ALL, 'en_US')
working_directory = os.path.dirname(os.path.dirname(os.path.realpath(__file__)))

def save_file(out, rows, mode):
    print("Saving file " + out + " ... ")

    start_time = time.time()
    with open(out, mode) as outfile:
        dict_writer = csv.DictWriter(outfile, rows[0].keys())
        if mode != "a+":
            dict_writer.writeheader()
        
        dict_writer.writerows(rows)
        
    print("Saved in %s seconds" % (time.time() - start_time))


def parse_author(my_file, data):
    
    print("Parsing authors from file " + my_file + " ... ")
    start_time = time.time()
    rows_author = Autor.parse_author(data)        
    print("Parsed in %s seconds" % (time.time() - start_time))

    return rows_author


def parse_commit(my_file, data, rows_author):

    print("Parsing commits from file " + my_file + " ... ")
    start_time = time.time()
    commit = Commit()
    rows_commit = commit.parse_commit(rows_author, data)
    print("Parsed in %s seconds" % (time.time() - start_time))

    return rows_commit


def parse_variability(my_file, data):

    print("Parsing variabilities from file " + my_file + " ... ")
    start_time = time.time()
    var = Variability()
    rows_variability = var.parse_variability(data)
    print("Parsed in %s seconds" % (time.time() - start_time))

    return rows_variability


def main():
    
    for root, dirs, files in os.walk(working_directory + '/data'):
        for f in sorted(files):
        #for f in ["Xterm.json"]:
            if '.json' in f:
                try:
                    with open(working_directory + '/data/' + f) as jfile:

                        my_file = f.split('.')[0]
                        print("Loading file " + my_file + " ... ", end='')
                        data = json.load(jfile)[my_file]
                        print("[OK]")

                        rows_author = parse_author(my_file, data)
                        rows_commit = parse_commit(my_file, data, rows_author)
                        rows_variability = parse_variability(my_file, data)

                        newpath = working_directory + '/resultados/' + my_file;
                        if not os.path.exists(newpath):
                            os.makedirs(newpath)

                        if toCsv:
                            out = newpath + '/' + my_file + '_Authors.csv'
                            save_file(out, rows_author, 'w+')

                            out = newpath + '/' + my_file + '_Commits.csv'
                            save_file(out, rows_commit, 'w+')
            
                            if is_ln:
                                for r in rows_variability:
                                    r['qtd_commits_geral'] = round(math.log(1 + r['qtd_commits_geral']), 3)
                                    r['qtd_commits_dl'] = round(math.log(1 + r['qtd_commits_dl']), 3)
                                    r['qtd_commits_ac'] = round(math.log(1 + r['qtd_commits_ac']), 3)

                            out = newpath + '/' + my_file + '_Variabilities.csv'
                            save_file(out, rows_variability, 'w+')
                            
                        else:
                            odata = OrderedDict()
                            odata.update({"Autores": rows_author})
                            odata.update({"Commits": rows_commit})
                            odata.update({"Variabilidades": rows_variability})

                            out = newpath + '/' + my_file + '.ods'
                            print("Saving file " + out)

                            start_time = time.time()
                            save_data(out, odata)
                            print("Saved in %s seconds" % (time.time() - start_time))


                        print()
                except ValueError as error:
                    print("[FAIL]")
                    print("Invalid json: %s" % error)
                    print()

if __name__ == "__main__":
    main()
