#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import csv
import sys
import locale

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

    total = []
    os.chdir(working_directory)

    for root in sorted(os.listdir("resultados/")):
    #for root in ["Clamav"]:
        colaboradores = dict()
        autores = dict()
        
        with open("resultados/" + root + "/" + root + "_Authors.csv") as csvfile:
            reader = csv.DictReader(csvfile)

            commits = ""
            for r in reader:
                if r["commits"] != "" and commits != r["commits"]:
                    commits = r["commits"]

                if r["autor"] == "Colaborador" and r["variabilidades"] != "":
                    if r["variabilidades"] not in colaboradores:
                        colaboradores[r["variabilidades"]] = []

                    colaboradores[r["variabilidades"]].append({
                        "arquivo": r["arquivo"],
                        "commits": str_split(commits),
                        "variabilidades": r["variabilidades"],
                        "desenvolvedor": r["desenvolvedor"],
                        "autor": r["autor"]
                    })
                elif r["autor"] == "Autor" and r["variabilidades"] == "":
                    if r["desenvolvedor"] not in autores:
                        autores[r["desenvolvedor"]] = []

                    autores[r["desenvolvedor"]].append({
                        "arquivo": r["arquivo"],
                        "commits": str_split(commits),
                        "variabilidades": r["variabilidades"],
                        "desenvolvedor": r["desenvolvedor"],
                        "autor": r["autor"]
                    })
            
            csvfile.seek(0)

            for r in reader:
                if r["autor"] == "Autor" and r["variabilidades"] != "":
                    if r["variabilidades"] in colaboradores:
                        colaboradores.pop(r["variabilidades"])

                    if r["desenvolvedor"] in autores:
                        autores.pop(r["desenvolvedor"])

        print("Saving file: resultados/" + root + "/colaboradores_autores.csv ... ")
        with open("resultados/" + root + "/colaboradores_autores.csv", "w+") as outfile:
            dict_writer = csv.DictWriter(outfile, ["arquivo", "commits", "variabilidades", "desenvolvedor", "autor"])
            dict_writer.writeheader()

            for colab in colaboradores.values():
                dict_writer.writerows(colab)

            for aut in autores.values():
                dict_writer.writerows(aut)

        total.append({
            "Projeto": root,
            "Autores": len(autores.values()),
            "Colaboradores": len(colaboradores.values())
        })

    with open("total_colaboradores.csv", "w+") as outfile:
        dict_writer = csv.DictWriter(outfile, ["Projeto", "Autores", "Colaboradores"])
        dict_writer.writeheader()

        dict_writer.writerows(total)

if __name__ == "__main__":
    main()
