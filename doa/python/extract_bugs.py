#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import re
import csv
import sys
import locale
import urllib.request as rq

from bs4 import BeautifulSoup


base_url = "http://vbdb.itu.dk/"

csv.field_size_limit(sys.maxsize)

locale.setlocale(locale.LC_ALL, 'en_US')
working_directory = os.path.dirname(os.path.dirname(os.path.realpath(__file__)))


def str_split (commits):
    ids = []
    commits = commits.split(", ")
    for commit in commits:
        id_commit = commit.split("  -  ")[0]
        id_commit = id_commit.strip()
        ids.append(id_commit)

    return " - ".join(ids)


def main():

    rows = []
    with open(working_directory + '/bugs.csv') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:

            print(row)
            projeto = row["Projeto"]
            bug = row["commit"]

            url = base_url + projeto.lower() + "/" + bug + ".html"
            print(url)
            html = rq.urlopen(url)
            soup = BeautifulSoup(html, 'html.parser')

            lk = soup.select("div.desc > a")[0].get("href")
            print(lk)
            commit = lk.split("/")[-1]

            tr_rows = soup.body.table
            tr = tr_rows.contents[3]

            tdtexto = tr.contents[1].text

            tdtexto = re.sub("\"", "", tdtexto)
            variability = re.sub("\([0-9]+(st|nd|rd|th) degree\)", "", tdtexto)
            variability = variability.strip()

            autor = ""
            with open(working_directory + '/resultados/' + projeto + '/' + projeto + '_Commits.csv') as cofile:
                coreader = csv.DictReader(cofile)
                for corow in coreader:
                    if corow['commit'] != commit:
                        continue

                    doa = 0.0
                    autor = corow['desenvolvedor']

                    with open(working_directory + '/resultados/' + projeto + '/' + projeto + '_Authors.csv') as aufile:
                        aureader = csv.DictReader(aufile)
                        for aurow in aureader:
                            if aurow['desenvolvedor'] != autor or aurow['arquivo'] != corow['arquivo']:
                                continue

                            doa = aurow['doa_n']
                            break

                    rows.append({
                        "projeto": projeto,
                        "url": url,
                        "bug": bug,
                        "variability": variability,
                        "arquivo": corow['arquivo'],
                        "commit": commit,
                        "autor": autor,
                        "doa": doa,
                        "ownership": corow['ownership_final']
                    })


            if len(autor) == 0:  
                rows.append({
                    "projeto": projeto,
                    "url": url,
                    "bug": bug,
                    "variability": "-"*50,
                    "arquivo": "-"*50,
                    "commit": commit,
                    "autor": "-"*50,
                    "doa": "-"*50,
                    "ownership": "-"*50
                })

    with open(working_directory + '/bugs_extraidos.csv', 'w+') as outfile:
        dict_writer = csv.DictWriter(outfile, rows[0].keys())
        dict_writer.writeheader()
        
        dict_writer.writerows(rows)


if __name__ == "__main__":
    main()
