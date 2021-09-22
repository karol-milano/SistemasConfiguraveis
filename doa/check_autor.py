#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import json
import math
import time

from dateutil.parser import *

from datetime import datetime


working_directory = os.path.dirname(os.path.realpath(__file__))

def doa_a (fa, dl, ac):
    total = 3.293 + 1.098 * fa + 0.164 * dl - 0.321 * math.log(1 + ac)
    return total


def parse_author(json_data):

    for filename, filedata in json_data['Arquivos'].items():
        
        if filename != "amqp1.c":
            continue

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

            dev = "Colaborador"

            fa = 0
            if auth == authorname:
                fa = 1
                dev = "Autor"

            abs_doa = doa_a(fa, dl, (ac - dl))

            if abs_doa > max_doa:
                max_doa = abs_doa

            frow.append({
                "desenvolvedor": authorname, 
                "arquivo": filename, 
                "fa": fa, 
                "dl": dl, 
                "ac": (ac - dl),
                "doa_a": abs_doa, 
                "doa_n": 0.0,
                "autor": (abs_doa > 3.293)
            })


        for r in frow:
            if max_doa == r["doa_a"]:
                r["doa_n"] = 1.0
            else:
                r["doa_n"] = r["doa_a"] / max_doa
                
        for r in frow:
            print(r)


def main():

    with open(working_directory + '/data/Collected.json') as jfile:
        parse_author(json.load(jfile)["Collected"])

if __name__ == "__main__":
    main()
