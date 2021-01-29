#!/usr/bin/env python
# -*- coding: utf-8 -*-

def create_author(id_commit, author_name, file_name, date, variabilities):
    author_data = {}
    author_data["Arquivos"] = {}
    author_data["Commits"] = {}
    author_data["Variabilidades"] = {}

    commit = id_commit + "  -  " + date
    fname = file_name + "  -  " + date

    author_data["Arquivos"][file_name] = {}
    author_data["Arquivos"][file_name]["Variabilidades"] = variabilities
    author_data["Arquivos"][file_name]["Commits"] = [ commit ]
        
    author_data["Commits"][id_commit] = {}
    author_data["Commits"][id_commit]["Variabilidades"] = variabilities
    author_data["Commits"][id_commit]["Arquivos"] = [ fname ]

    for var in variabilities:
        author_data["Variabilidades"][var] = {}
        author_data["Variabilidades"][var]["Arquivos"] = [ file_name ]
        author_data["Variabilidades"][var]["Commits"] = [ commit ]
    
    return author_data


def update_author(author_data, id_commit, author_name, file_name, date, variabilities):
    """
    """
    
    commit = id_commit + "  -  " + date
    fname = file_name + "  -  " + date

    if file_name in author_data["Arquivos"]:
        for var in variabilities:
            if var not in author_data["Arquivos"][file_name]["Variabilidades"]:
                author_data["Arquivos"][file_name]["Variabilidades"].append(var)

        if commit not in author_data["Arquivos"][file_name]["Commits"]:
            author_data["Arquivos"][file_name]["Commits"].append(commit)
    else:
        author_data["Arquivos"][file_name] = {}
        author_data["Arquivos"][file_name]["Variabilidades"] = variabilities
        author_data["Arquivos"][file_name]["Commits"] = [ commit ]
        
    if id_commit in author_data["Commits"]:
        for var in variabilities:
            if var not in author_data["Commits"][id_commit]["Variabilidades"]:
                author_data["Commits"][id_commit]["Variabilidades"].append(var)

        if fname not in author_data["Commits"][id_commit]["Arquivos"]:
            author_data["Commits"][id_commit]["Arquivos"].append(fname)
    else:
        author_data["Commits"][id_commit] = {}
        author_data["Commits"][id_commit]["Variabilidades"] = variabilities
        author_data["Commits"][id_commit]["Arquivos"] = [ fname ]

    for var in variabilities:
        if var in author_data["Variabilidades"]:
            if file_name not in author_data["Variabilidades"][var]["Arquivos"]:
                author_data["Variabilidades"][var]["Arquivos"].append(file_name)
                
            if commit not in author_data["Variabilidades"][var]["Commits"]:
                author_data["Variabilidades"][var]["Commits"].append(commit)
        else:
            author_data["Variabilidades"][var] = {}
            author_data["Variabilidades"][var]["Arquivos"] = [ file_name ]
            author_data["Variabilidades"][var]["Commits"] = [ commit ]
    

    return author_data