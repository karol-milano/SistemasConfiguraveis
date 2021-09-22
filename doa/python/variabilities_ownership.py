#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import csv
import locale

locale.setlocale(locale.LC_ALL, 'en_US')
working_directory = os.path.dirname(os.path.dirname(os.path.realpath(__file__)))


def main():

    total = []
    os.chdir(working_directory)

    for root in sorted(os.listdir("resultados/")):
    #for root in ["Xterm"]:
        minors = dict()
        majors = dict()
        
        with open("resultados/" + root + "/" + root + "_Commits.csv") as csvfile:
            reader = csv.DictReader(csvfile)

            for r in reader:
                if r["classificacao_ownership_final"] == "Minor" and r["variabilidades"] != "":
                    if r["variabilidades"] not in minors:
                        minors[r["variabilidades"]] = []

                    minors[r["variabilidades"]].append({
                        "arquivo": r["arquivo"],
                        "commit": r["commit"],
                        "variabilidades": r["variabilidades"],
                        "desenvolvedor": r["desenvolvedor"],
                        "classificacao_ownership_final": r["classificacao_ownership_final"]
                    })
                elif r["classificacao_ownership_final"] == "Major" and r["variabilidades"] == "":
                    if r["desenvolvedor"] not in majors:
                        majors[r["desenvolvedor"]] = []

                    majors[r["desenvolvedor"]].append({
                        "arquivo": r["arquivo"],
                        "commit": r["commit"],
                        "variabilidades": r["variabilidades"],
                        "desenvolvedor": r["desenvolvedor"],
                        "classificacao_ownership_final": r["classificacao_ownership_final"]
                    })
            
            csvfile.seek(0)

            for r in reader:
                if r["classificacao_ownership_final"] == "Major" and r["variabilidades"] != "":
                    if r["variabilidades"] in minors:
                        minors.pop(r["variabilidades"])

                    if r["desenvolvedor"] in majors:
                        majors.pop(r["desenvolvedor"])

        print("Saving file: resultados/" + root + "/minors_majors.csv ... ")
        with open("resultados/" + root + "/minors_majors.csv", "w+") as outfile:
            dict_writer = csv.DictWriter(outfile, ["arquivo", "commit", "variabilidades", "desenvolvedor", "classificacao_ownership_final"])
            dict_writer.writeheader()

            for min in minors.values():
                dict_writer.writerows(min)
            
            for maj in majors.values():
                dict_writer.writerows(maj)

        total.append({
            "Projeto": root,
            "Majors": len(majors.values()),
            "Minors": len(minors.values())
        })

    with open("total_minors.csv", "w+") as outfile:
        dict_writer = csv.DictWriter(outfile, ["Projeto", "Majors", "Minors"])
        dict_writer.writeheader()

        dict_writer.writerows(total)

if __name__ == "__main__":
    main()
