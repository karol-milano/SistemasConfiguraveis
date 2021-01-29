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


def save_file(output, writeheader, rows):
	print("Saving file " + output + " ... ")
	start_time = time.time()
	with open(output, 'a+') as outfile:
		dict_writer = csv.DictWriter(outfile, rows[0].keys())
		if writeheader:
			dict_writer.writeheader()
		
		dict_writer.writerows(rows)
		
	print("Saved in %s seconds\n" % (time.time() - start_time))


def main():
	first_save = True
	for root, dirs, files in os.walk(working_directory + '/data'):
		for f in sorted(files):
		#for f in ["Bison.json", "Collectd.json", "Gnuplot.json", "LibPng.json", "Libssh.json", "Lighttpd.json", "M4.json", "OpenSC.json", "Openvpn.json", "Totem.json", "Uwsgi.json", "Xterm.json"]:
		#for f in ["Bison.json", "Cherokee.json"]:
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
						
						output = "Variabilities_final.csv"

						for r in rows:
							r['qtd_commits_geral'] = round(math.log(1 + r['qtd_commits_geral']), 3)
							r['qtd_commits_dl'] = round(math.log(1 + r['qtd_commits_dl']), 3)
							r['qtd_commits_ac'] = round(math.log(1 + r['qtd_commits_ac']), 3)

						save_file(output, first_save, rows)

						first_save = False

						print()
				except ValueError as error:
					print("[FAIL]")
					print("Invalid json: %s" % error)
					print()

if __name__ == "__main__":
	main()
 
