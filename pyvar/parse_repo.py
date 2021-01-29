#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import csv
import json
import time
import progressbar

from preprocessor import Preprocessor

from arquivo import *
from autor import *
from commit import *
from variabilidade import *


def find_files():
    """
    """

    data_dir = os.path.dirname(os.path.realpath(__file__))
    data_dir = os.path.join(data_dir, "repositories")

    files = [f for f in os.listdir(data_dir) if len(f.split(".")) == 2]

    for file_name in sorted(files):
        name, ext = file_name.split(".")
        if ext == "csv":
            print("\n" + name)
            parse_repo(name)


def parse_repo(projeto = "Cherokee"):
    """
    """

    data_dir = os.path.dirname(os.path.realpath(__file__))
    data_dir = os.path.join(data_dir, "repositories")
    data_dir = os.path.join(data_dir, projeto)

    results_dir = os.path.dirname(os.path.realpath(__file__))
    results_dir = os.path.join(results_dir, "results")
    projeto_dir = os.path.join(results_dir, projeto)

    if not os.path.exists(projeto_dir):
        os.makedirs(projeto_dir)

    data = {}
    data[projeto] = {}
    data[projeto]["Arquivos"] = {}
    data[projeto]["Autores"] = {}
    data[projeto]["Commits"] = {}
    data[projeto]["Variabilidades"] = {}

    with open(data_dir + ".csv") as csv_file:
        row_count = sum(1 for row in csv_file)
        csv_file.seek(0, 0)

        csv_reader = csv.DictReader(csv_file)

        widgets = [' [', 
            progressbar.Timer(format= 'elapsed time: %(elapsed)s'), 
            '] ', 
            progressbar.Bar('*'),' (', 
            progressbar.ETA(), ') ', 
        ]
  
        bar = progressbar.ProgressBar(max_value=row_count, widgets=widgets).start() 

        output_var_csv = os.path.join(results_dir, projeto + ".csv")
        with open(output_var_csv, "w+") as output_csv:
            header = [
                "Commit",
                "Data",
                "Autor",
                "Arquivo",
                "Mudança por arquivo",
                "Variabilidade",
                "Mudança por variabilidade"
            ]

            dict_writer = csv.DictWriter(output_csv, header)
            dict_writer.writeheader()

            for i, row in enumerate(csv_reader):
                if int(row['FileCount']) > 0:

                    id_commit = row['Commit'].strip()
                    author_name = row['Author'].strip()
                    date = row['Date'].strip()

                    input_path = os.path.join(data_dir, id_commit)
                    output_path = os.path.join(projeto_dir, id_commit)

                    for root, dirs, files in os.walk(input_path):
                        for file_name in sorted(files):
                            ext = file_name.split(".")[-1]
                            if ext != "c" and ext != "h" and ext != "cpp" and ext != "hpp":
                                continue

                            root_dir = os.path.join(input_path, root)
                            input_file = os.path.join(root_dir, file_name)
                            
                            tmp = root_dir.split(id_commit)
                            output = output_path + tmp[1]

                            if not os.path.exists(output):
                                os.makedirs(output)

                            output_file = os.path.join(output, file_name + ".var")
                
                            preprocessor = Preprocessor()
                            var_list, buffer = preprocessor.parse_save(input_file, output_file, id_commit, date, author_name, root + "/" + file_name)

                            dict_writer.writerows(buffer)
                            
                            #################################################################################
                            ############## Arquivos
                            #################################################################################
                            if file_name in data[projeto]["Arquivos"]:
                                data[projeto]["Arquivos"][file_name] = update_arquivo(data[projeto]["Arquivos"][file_name], id_commit, author_name, file_name, date, var_list)
                            else:
                                data[projeto]["Arquivos"][file_name] = create_arquivo(id_commit, author_name, file_name, date, var_list)


                    for root, dirs, files in os.walk(input_path):
                        for file_name in sorted(files):
                            ext = file_name.split(".")[-1]
                            if ext != "c" and ext != "h" and ext != "cpp" and ext != "hpp":
                                continue

                            root_dir = os.path.join(input_path, root)
                            input_file = os.path.join(root_dir, file_name)
                
                            preprocessor = Preprocessor()
                            var_list = preprocessor.parse(input_file)

                            #################################################################################
                            ############## Autores
                            #################################################################################
                            if author_name in data[projeto]["Autores"]:
                                data[projeto]["Autores"][author_name] = update_author(data[projeto]["Autores"][author_name], id_commit, author_name, file_name, date, var_list)
                            else:
                                data[projeto]["Autores"][author_name] = create_author(id_commit, author_name, file_name, date, var_list)


                    for root, dirs, files in os.walk(input_path):
                        for file_name in sorted(files):
                            ext = file_name.split(".")[-1]
                            if ext != "c" and ext != "h" and ext != "cpp" and ext != "hpp":
                                continue

                            root_dir = os.path.join(input_path, root)
                            input_file = os.path.join(root_dir, file_name)

                            preprocessor = Preprocessor()
                            var_list = preprocessor.parse(input_file)

                            #################################################################################
                            ############## Commits
                            #################################################################################
                            if id_commit in data[projeto]["Commits"]:
                                data[projeto]["Commits"][id_commit] = update_commit(data[projeto]["Commits"][id_commit], id_commit, author_name, file_name, date, var_list)
                            else:
                                data[projeto]["Commits"][id_commit] = create_commit(id_commit, author_name, file_name, date, var_list)


                    for root, dirs, files in os.walk(input_path):
                        for file_name in sorted(files):
                            ext = file_name.split(".")[-1]
                            if ext != "c" and ext != "h" and ext != "cpp" and ext != "hpp":
                                continue

                            root_dir = os.path.join(input_path, root)
                            input_file = os.path.join(root_dir, file_name)
                
                            preprocessor = Preprocessor()
                            var_list = preprocessor.parse(input_file)

                            #################################################################################
                            ############## Variabilidades
                            #################################################################################
                            for var in var_list:
                                if var in data[projeto]["Variabilidades"]:
                                    data[projeto]["Variabilidades"][var] = update_variability(data[projeto]["Variabilidades"][var], id_commit, author_name, file_name, date, var)
                                else:
                                    data[projeto]["Variabilidades"][var] = create_variability(id_commit, author_name, file_name, date, var)

                bar.update(i)

        print()

    #################################################################################################
    #### Salva o JSON no arquivo
    #################################################################################################

    output_json = os.path.join(results_dir, projeto + ".json")
    with open(output_json, "w+") as json_file:
        json.dump(data, json_file, indent = 4, sort_keys = True)


if __name__ == "__main__":
    find_files()
    #parse_repo()
