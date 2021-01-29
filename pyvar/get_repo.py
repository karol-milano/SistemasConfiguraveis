#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import csv
import unidecode
import progressbar

from pydriller import RepositoryMining

def main():

    working_directory = os.path.dirname(os.path.realpath(__file__))
    working_directory = os.path.join(working_directory, "repositories")

    with open("repositories.csv") as csv_file:
        csv_reader = csv.DictReader(csv_file)
        for row in csv_reader:
            print(row)

            projeto = row['Projeto']
            baixar = int(row['Baixar'])
            url = row['Url']

            if baixar == 0:
                continue

            repos_dir = os.path.join(working_directory, projeto)
            rm = RepositoryMining(url)

            print("Cloning repository: " + projeto)

            with open(repos_dir + ".csv", 'w') as csv_file:
                dict_writer = csv.DictWriter(csv_file, ["Commit", "Author", "Date", "FileCount"])
                dict_writer.writeheader()
                
                autores = dict()

                widgets = ['Loading: ', progressbar.AnimatedMarker()] 
                bar = progressbar.ProgressBar(widgets=widgets).start()

                for i, commit in enumerate(rm.traverse_commits()):

                    email = commit.author.email.lower().strip()
                    name = unidecode.unidecode(commit.author.name.title().strip())

                    if email not in autores:
                        autores[email] = name
                    else:
                        name = autores[email]

                    path = os.path.join(repos_dir, commit.hash)

                    file_count = 0
                    for modified_file in commit.modifications:
                        ext = modified_file.filename.split(".")[-1]
                        if ext != "c" and ext != "cpp":
                            continue

                        aux = ""
                        file_count += 1
                        if modified_file.new_path is not None:
                            aux = modified_file.new_path.split("/")
                        elif modified_file.old_path is not None:
                            aux = modified_file.old_path.split("/")

                        modified = os.path.join(path, "/".join(aux[1:-1]))
                        if not os.path.exists(modified):
                            os.makedirs(modified)

                        modified = os.path.join(modified, modified_file.filename)

                        with open(modified, 'w') as f:
                            f.write(modified_file.diff)

                    dict_writer.writerow({
                        "Commit": commit.hash,
                        "Author": name,
                        "Date": commit.author_date,
                        "FileCount": file_count
                    })

                    bar.update(i)
            
            print()
            print("="*150)


if __name__ == "__main__":
    main()
