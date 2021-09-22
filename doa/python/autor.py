#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import re  # biblioteca expressão regular
import math
from dateutil.parser import *
from datetime import datetime, timezone

class Autor:
	
	def doa_a (fa, dl, ac):
		"""
		Calcula e retorna o doa_a de um desenvolvedor para um arquivo
		:param fa: (first authorship) quem fez o commit criando o arquivo
		:param dl: (deliveries) quantidade de commits aceitos
		:param ac: () quantidade de commits aceitos que outros desenvolvedores realizaram
		"""
		total = 3.293 + 1.098 * fa + 0.164 * dl - 0.321 * math.log(1 + ac)
		return total


	def parse_author(json_data):
		rows = []
		lista = []

		for filename, filedata in json_data['Arquivos'].items():

			ac = 0
			auth = ""
			frow = []
			max_doa = -1.0
			criacao = datetime.now()

			for authorname, authordata in filedata['Autores'].items():
				ac += len(authordata['Commits'])

				#ta = re.search('\(([^)]+)', authordata['Commits'][-1]).group(1)
				ta = authordata['Commits'][-1].split("  -  ")[1]
				timeAuthor = parse(ta.strip(), ignoretz=True)
				#timeAuthor = parse(ta.strip())
				if timeAuthor < criacao:
					criacao = timeAuthor
					auth = authorname

			for authorname, authordata in filedata['Autores'].items():
				dl = len(authordata['Commits'])

				fa = 0
				if auth == authorname:
					fa = 1

				abs_doa = Autor.doa_a(fa, dl, (ac - dl))
				
				if abs_doa > max_doa:
					max_doa = abs_doa

				found = "False"
				variabilities = []
				for var in authordata['Variabilidades']:
					aux = var.split("  -  ")[0].strip()

					if "TRUE" == aux:
						found = "True"
					else:
						variabilities.append(aux)

				classificacao = "Especialista"
				if found == "True":
					if len(variabilities) > 0:
						classificacao = "Misto"
					else:
						classificacao = "Generalista"

				variabilities_length = len(variabilities)
				if len(variabilities) == 0:
					variabilities = ""

				frow.append({
					"desenvolvedor": authorname, 
					"arquivo": filename, 
					"qtd_variabilidades": variabilities_length, 
					"existencia": found, 
					"variabilidades": variabilities,
					"qtd_commits": dl, 
					"commits": ", ".join(authordata['Commits']), 
					"doa_a": abs_doa, 
					"doa_n": 0.0, 
					"classificacao": classificacao, 
					"autor": ""
				})


			for r in frow:
				if max_doa == r["doa_a"]:
					r["doa_n"] = 1.0
				else:
					r["doa_n"] = r["doa_a"] / max_doa

				if r["doa_a"] > 3.293 and r["doa_n"] > 0.75:
					r["autor"] = "Autor"
				else:
					r["autor"] = "Colaborador"

				if r["qtd_variabilidades"] == 0:
					rows.append(r)
				else:
					rows.append({
						"desenvolvedor": r["desenvolvedor"], 
						"arquivo": r["arquivo"], 
						"qtd_variabilidades": r["qtd_variabilidades"], 
						"existencia": r["existencia"], 
						"variabilidades": r["variabilidades"][0],
						"qtd_commits": r["qtd_commits"], 
						"commits": r["commits"], 
						"doa_a": r["doa_a"], 
						"doa_n": r["doa_n"], 
						"classificacao": r["classificacao"], 
						"autor": r["autor"]
						})

					if r["qtd_variabilidades"] > 1:
						for i in range(1, r["qtd_variabilidades"]):
							rows.append({
								"desenvolvedor": r["desenvolvedor"], 
								"arquivo": r["arquivo"], 
								"qtd_variabilidades": "", 
								"existencia": "", 
								"variabilidades": r["variabilidades"][i],
								"qtd_commits": "", 
								"commits": "",
								"doa_a": "",
								"doa_n": "", 
								"classificacao": "",
								"autor": r["autor"]
								})

		return rows
