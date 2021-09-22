#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import re  # biblioteca expressão regular

from dateutil.parser import *

from operator import itemgetter

class Commit:

    def str_split (self, name):
        name = name.split("  -  ")[0]
        name = name.strip()

        return name


    def conta_ownership(self, rows, dict_total, dict_conta_arquivo):
        """
            Função utilizada para calcular o ownership do arquivo
        """

        for r in rows:
            if r['qtd_variabilidades'] == "":
                continue

            if r['arquivo'] in dict_total:
                total = dict_total.get(r['arquivo'])

                total += 1
                dict_total[r['arquivo']] = total
            else:
                dict_total[r['arquivo']] = 1

            if (r['arquivo'], r['desenvolvedor']) in dict_conta_arquivo:
                conta = dict_conta_arquivo.get((r['arquivo'], r['desenvolvedor']))

                conta += 1
                dict_conta_arquivo[(r['arquivo'], r['desenvolvedor'])] = conta
            else:
                dict_conta_arquivo[(r['arquivo'], r['desenvolvedor'])] = 1

        for r in rows:
            ownership = dict_conta_arquivo.get((r['arquivo'], r['desenvolvedor']))
            total = dict_total.get(r['arquivo'])
            r['ownership'] =  100 * float(ownership) / float(total)

            classificacao_ownership = "Minor"

            if r['ownership'] > 5:
                classificacao_ownership = "Major"

            r['classificacao_ownership'] = classificacao_ownership


    def classificacao_tempo (self, rows, dict_total, dict_conta_arquivo):
        """
        
        """

        begin = end = 0
        rows = sorted(rows, key = itemgetter('data'))

        data = rows[0]['data']
        for r in rows:
            if data != r['data']:
                self.conta_ownership(rows[begin:end], dict_total, dict_conta_arquivo)
                begin = end
                data = r['data']
                end += 1
            else:
                end += 1

        self.conta_ownership(rows[begin:end], dict_total, dict_conta_arquivo)
        return rows


    def conta_ownership_final(self, rows, dict_total, dict_conta_arquivo):
        """
        """

        for r in rows:
            ownership = dict_conta_arquivo.get((r['arquivo'], r['desenvolvedor']))
            total = dict_total.get(r['arquivo'])
            ownership =  100 * float(ownership) / float(total)

            classificacao_ownership = "Minor"

            if ownership > 5:
                classificacao_ownership = "Major"

            r['ownership_final'] = ownership
            r['classificacao_ownership_final'] = classificacao_ownership


    def parse_commit(self, rows_author, json_data):
        rows = []
        crows = []

        for r in rows_author:
            commits = r["commits"].split(", ")

            for commit in commits:

                if commit == "":
                    continue

                idCommit, commitData = commit.split("  -  ")

                idCommit = idCommit.strip()
                #commitData = re.search('\(([^)]+)', commitData).group(1)
                commitData = parse(commitData.strip(), ignoretz=True)

                found = "False"
                variabilities = []
                
                if idCommit in json_data['Commits']:
                    if r['arquivo'] in json_data['Commits'][idCommit]['Arquivos']:
                        jvar = json_data['Commits'][idCommit]['Arquivos'][r['arquivo']]['Variabilidades']

                        for var in jvar:
                            aux = self.str_split(var)

                            if aux == "TRUE":
                                found = "True"
                            else:
                                variabilities.append(aux)

                        var = ""
                        if len(variabilities) != 0:
                            var = variabilities[0]

                        crows.append({
                            "commit": idCommit,
                            "data": commitData.strftime("%Y-%m-01"),
                            "desenvolvedor": r["desenvolvedor"], 
                            "arquivo": r["arquivo"],
                            "qtd_variabilidades": len(variabilities), 
                            "existencia": found, 
                            "variabilidades": var,
                            "classificacao": "", 
                            "ehautor": r["autor"],
                            "ownership": 0,
                            "classificacao_ownership": "",
                            "ownership_final": 0,
                            "classificacao_ownership_final": ""
                        })

                        if len(variabilities) > 0:
                            for i in range(1, len(variabilities)):
                                crows.append({
                                    "commit": idCommit,
                                    "data": commitData.strftime("%Y-%m-01"),
                                    "desenvolvedor": r["desenvolvedor"], 
                                    "arquivo": r["arquivo"],
                                    "qtd_variabilidades": "",
                                    "existencia": "", 
                                    "variabilidades": variabilities[i],
                                    "classificacao": "", 
                                    "ehautor": r["autor"],
                                    "ownership": 0,
                                    "classificacao_ownership": "",
                                    "ownership_final": 0,
                                    "classificacao_ownership_final": ""
                                })
                                
        rows = sorted(crows, key = itemgetter('commit'))

        idx = 0
        gen = 0
        esp = 0
        idCommit = ""
        for i, r in enumerate(rows):

            if idCommit != r["commit"]:
                
                if gen > 0:
                    if esp > 0:
                        classificacao = "Misto"
                    else:
                        classificacao = "Generalista"
                else:
                    classificacao = "Especialista"

                for j in range(idx, i):
                    rows[j]["classificacao"] = classificacao

                idx = i
                gen = 0
                esp = 0
                idCommit = r["commit"]

                if len(r["variabilidades"]) > 0:
                    esp += 1

                if r["existencia"] == "True":
                    gen += 1

        if gen > 0:
            if esp > 0:
                classificacao = "Misto"
            else:
                classificacao = "Generalista"
        else:
            classificacao = "Especialista"

        for j in range(idx, len(rows)):
            rows[j]["classificacao"] = classificacao

        rows = sorted(crows, key = itemgetter('data'))
        dict_nome = dict()
        
        for i, r in enumerate(rows):
            if r['desenvolvedor'] in dict_nome:
                if dict_nome[r['desenvolvedor']] != r['classificacao']:
                    dict_nome[r['desenvolvedor']] = "Misto"
                    
                    dev = r['desenvolvedor']
                    data = r['data']
                    for j in range(i, 0, -1):
                        if rows[j]['desenvolvedor'] == dev:
                            if rows[j]['data'] != data:
                                break
                            
                            rows[j]['classificacao'] = "Misto"
            else:
                dict_nome[r['desenvolvedor']] = r['classificacao']

        dict_total = dict()
        dict_conta_arquivo = dict()
        self.classificacao_tempo(rows, dict_total, dict_conta_arquivo)
        self.conta_ownership_final(rows, dict_total, dict_conta_arquivo)

        return rows
