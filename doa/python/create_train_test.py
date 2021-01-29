#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import csv
import json
import math
import time
import locale
import random

from variability import Variability

locale.setlocale(locale.LC_ALL, 'en_US')
working_directory = os.path.dirname(os.path.dirname(os.path.realpath(__file__)))


def save_file(output, writeheader, rows, begin, end):
	print("Saving file " + output + " ... ")
	start_time = time.time()
	with open(output, 'a+') as outfile:
		dict_writer = csv.DictWriter(outfile, rows[0].keys())
		if writeheader:
			dict_writer.writeheader()
		
		dict_writer.writerows(rows[begin : end])
		
	print("Saved in %s seconds\n" % (time.time() - start_time))


def parse_variability(rows, first_test, first_train):
	
	train_output = "Variabilities_train.csv"
	test_output = "Variabilities_test.csv"

	size = len(rows)
	train_size = size * 20 // 100

	random.shuffle(rows[1:])

	save_file(train_output, first_train, rows, 1, train_size)
	save_file(test_output, first_test, rows, train_size + 1, size)

	####################################################################################

	test_output = "Variabilities_ln_test.csv"
	train_output = "Variabilities_ln_train.csv"
	for r in rows:
		r['qtd_commits_geral'] = round(math.log(1 + r['qtd_commits_geral']), 3)
		r['qtd_commits_dl'] = round(math.log(1 + r['qtd_commits_dl']), 3)
		r['qtd_commits_ac'] = round(math.log(1 + r['qtd_commits_ac']), 3)


	save_file(train_output, first_train, rows, 1, train_size)
	save_file(test_output, first_test, rows, train_size + 1, size)

#########################################################################################


def main():
	first_test = True
	first_train = True
	for root, dirs, files in os.walk(working_directory + '/data'):
		for f in sorted(files):
			if '.json' in f:
				try:
					with open(working_directory + '/data/' + f) as jfile:

						my_file = f.split('.')[0]
						print("Loading file " + my_file + " ... ", end='')
						data = json.load(jfile)[my_file]
						print("[OK]")

						print("Parsing variabilities from file " + my_file + " ... ")
						start_time = time.time()
						var = Variability()
						rows = var.parse_variability(data)
						print("Parsed in %s seconds" % (time.time() - start_time))						
						
						output = "Variabilities.csv"	
						save_file(output, first_train, rows, 1, len(rows))

						parse_variability(rows, first_test, first_train)

						first_test = False
						first_train = False

						print()
				except ValueError as error:
					print("[FAIL]")
					print("Invalid json: %s" % error)
					print()

if __name__ == "__main__":
	main()