#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import csv
import json

def str_split(name):
	name = name.split("  -  ")[0]
	name = name.strip()

	return name

def parse_file(project, json_data):
	rows = []
	
	for varname, vardata in json_data['Variabilidades'].items():
		for id_commit, commitdata in vardata['Commits'].items():
			for filename in commitdata['Arquivos']:
				fname = str_split(filename)

				if id_commit not in json_data['Commits']:
					rows.append({
						"projeto": project,
						"variabilidade": varname,
						"arquivo": fname,
						"commit": id_commit 
					})

					continue



				files = json_data['Commits'][id_commit]['Arquivos']
				if fname not in files:
					rows.append({
						"projeto": project,
						"variabilidade": varname,
						"arquivo": fname,
						"commit": id_commit 
					})

					continue
						
				
			
		for authorname, authordata in vardata['Autores'].items():
			for filename in authordata['Arquivos']:
				fname = str_split(filename)

				for commit in authordata['Commits']:
					id_commit = str_split(commit)

					if id_commit not in json_data['Commits']:
						rows.append({
							"projeto": project,
							"variabilidade": varname,
							"arquivo": fname,
							"commit": id_commit 
						})
						
					
	rows.append({
		"projeto": "",
		"variabilidade": "",
		"arquivo": "",
		"commit": "" 
	})

	return rows

def main():
	working_directory = os.path.dirname(os.path.realpath(__file__))


	for root, dirs, files in os.walk(working_directory + '/data'):
		for f in sorted(files):
			if '.json' in f:
				with open(working_directory + '/data/' + f) as jfile:
					my_file = f.split('.')[0]
					print("Loading file " + my_file + " ... ")
					data = json.load(jfile)[my_file]
					
					rows = parse_file(my_file, data)

					print("Found %d errors" % ( len(rows) ))
					outname = my_file + '_commits_errados.csv'
					with open(outname, 'w') as outfile:
						fieldnames = ['projeto', 'variabilidade', 'arquivo', 'commit']
						dict_writer = csv.DictWriter(outfile, fieldnames)
						dict_writer.writeheader()
						dict_writer.writerows(rows)

					print()

						
if __name__ == "__main__":
	main()