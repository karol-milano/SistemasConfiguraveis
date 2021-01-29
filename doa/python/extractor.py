#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import re  # biblioteca expressão regular

from dateutil.parser import *

from operator import itemgetter

class Extractor:

	def get_first_field (self, name):
		name = name.split("  -  ")[0]
		name = name.strip()

		return name


	def count_variabilities_by_month (self, json_data):
		rows = []
		vardict = dict()

		for filename, filedata in json_data['Arquivos'].items():
			for idcommit, commitdata in filedata['Commits'].items():

				for var in commitdata['Variabilidades']:
					var = self.get_first_field(var)

					if var == "TRUE":
						continue

					if var in json_data['Variabilidades']:
						if filename in json_data['Variabilidades'][var]['Arquivos']:

							for commit in json_data['Variabilidades'][var]['Arquivos'][filename]['Commits']:
								
								idc, data = commit.split("  -  ")

								idc = idc.strip()
								if idc == idcommit:

									data = re.search('\(([^)]+)', data).group(1)
									data = parse(data.strip(), ignoretz=True)
									data = data.strftime("%Y-%m")

									if data in vardict:
										if var not in vardict[data]:
											vardict[data].append(var)
									else:
										vardict.setdefault(data, []).append(var)

		for k, v in vardict.items():
			rows.append({
				"data": k,
				"n_variabilities": len(v),
				"variabilities": v
			})

		return sorted(rows, key = itemgetter('data'))


	def count_author_by_month (self, json_data):
		rows = []
		mdict = dict()

		for idcommit, commitdata in json_data['Commits'].items():
			gen = 0
			esp = 0

			data = ""
			for filename, filedata in commitdata['Arquivos'].items():

				for var in filedata['Variabilidades']:

					var, data = var.split("  -  ")
					var = var.strip()

					data = re.search('\(([^)]+)', data).group(1)
					data = parse(data.strip(), ignoretz=True)
					data = data.strftime("%Y-%m")

					if var == "TRUE":
						gen += 1
					else:
						esp += 1


			if data in mdict:
				d_gen, d_esp, d_mis = mdict.get(data)

				if gen > 0:
					if esp > 0:
						d_mis += 1
					else:
						d_gen += 1
				elif esp > 0:
					d_esp += 1

				mdict[data] = (d_gen, d_esp, d_mis)
			else:
				d_gen = d_esp = d_mis = 0

				if gen > 0:
					if esp > 0:
						d_mis += 1
					else:
						d_gen += 1
				elif esp > 0:
					d_esp += 1

				mdict[data] = (d_gen, d_esp, d_mis)

		for k, v in mdict.items():

			rows.append({
				"data": k,
				"n_generalista": v[0],
				"n_especialista": v[1],
				"n_misto": v[2],
				"total": v[0] + v[1] + v[2]
			})

		return sorted(rows, key = itemgetter('data'))
