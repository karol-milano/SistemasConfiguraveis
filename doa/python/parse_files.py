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

from extractor import Extractor

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


def count_variabilities_by_month(my_file, data):
	
	print("Parsing files from file " + my_file + " ... ")
	start_time = time.time()
	extractor = Extractor()
	rows_files = extractor.count_variabilities_by_month(data)		
	print("Parsed in %s seconds" % (time.time() - start_time))

	return rows_files


def count_author_by_month (my_file, data):

	print("Parsing files from file " + my_file + " ... ")
	start_time = time.time()
	extractor = Extractor()
	rows_files = extractor.count_author_by_month(data)		
	print("Parsed in %s seconds" % (time.time() - start_time))

	return rows_files


def main():
	
	for root, dirs, files in os.walk(working_directory + '/data'):
		for f in sorted(files):
		#for f in ["Cherokee.json"]:
			if '.json' in f:
				try:
					with open(working_directory + '/data/' + f) as jfile:

						my_file = f.split('.')[0]
						print("Loading file " + my_file + " ... ", end='')
						data = json.load(jfile)[my_file]
						print("[OK]")

						rows_files = count_variabilities_by_month(my_file, data)
						rows_author = count_author_by_month(my_file, data)

						newpath = working_directory + '/resultados/' + my_file;
						if not os.path.exists(newpath):
							os.makedirs(newpath)

						out = newpath + '/' + my_file + '_Count_Files.csv'
						save_file(out, rows_files, 'w+')

						out = newpath + '/' + my_file + '_Count_Authors.csv'
						save_file(out, rows_author, 'w+')

						print()
				except ValueError as error:
					print("[FAIL]")
					print("Invalid json: %s" % error)
					print()

if __name__ == "__main__":
	main()