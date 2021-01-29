#!/usr/bin/env python
# -*- coding: utf-8 -*-

def create_commit(id_commit, author_name, file_name, date, variabilities):
    commit_data = {}
    commit_data["Autores"] = {}
    commit_data["Arquivos"] = {}
    commit_data["Variabilidades"] = {}

    fname = file_name + "  -  " + date
    aname = author_name + "  -  " + date

    commit_data["Autores"][author_name] = {}
    commit_data["Autores"][author_name]["Variabilidades"] = variabilities
    commit_data["Autores"][author_name]["Arquivos"] = [ fname ]

    commit_data["Arquivos"][file_name] = {}
    commit_data["Arquivos"][file_name]["Variabilidades"] = variabilities
    commit_data["Arquivos"][file_name]["Autores"] = [ aname ]

    for var in variabilities:
        commit_data["Variabilidades"][var] = {}
        commit_data["Variabilidades"][var]["Autores"] = [ author_name ]
        commit_data["Variabilidades"][var]["Arquivos"] = [ fname ]

    return commit_data


def update_commit(commit_data, id_commit, author_name, file_name, date, variabilities):
    """
    """
    
    fname = file_name + "  -  " + date
    aname = author_name + "  -  " + date

    if author_name in commit_data["Autores"]:
        for var in variabilities:
            if var not in commit_data["Autores"][author_name]["Variabilidades"]:
                commit_data["Autores"][author_name]["Variabilidades"].append(var)

        if fname not in commit_data["Autores"][author_name]["Arquivos"]:
            commit_data["Autores"][author_name]["Arquivos"].append(fname)
    else:
        commit_data["Autores"][author_name] = {}
        commit_data["Autores"][author_name]["Variabilidades"] = variabilities
        commit_data["Autores"][author_name]["Arquivos"] = [ fname ]

    if file_name in commit_data["Arquivos"]:
        for var in variabilities:
            if var not in commit_data["Arquivos"][file_name]["Variabilidades"]:
                commit_data["Arquivos"][file_name]["Variabilidades"].append(var)

        if aname not in commit_data["Arquivos"][file_name]["Autores"]:
            commit_data["Arquivos"][file_name]["Autores"].append(aname)
    else:
        commit_data["Arquivos"][file_name] = {}
        commit_data["Arquivos"][file_name]["Variabilidades"] = variabilities
        commit_data["Arquivos"][file_name]["Autores"] = [ aname ]

    for var in variabilities:
        if var in commit_data["Variabilidades"]:
            if author_name not in commit_data["Variabilidades"][var]["Autores"]:
                commit_data["Variabilidades"][var]["Autores"].append(author_name)

            if fname not in commit_data["Variabilidades"][var]["Arquivos"]:
                commit_data["Variabilidades"][var]["Arquivos"].append(fname)
        else:
            commit_data["Variabilidades"][var] = {}
            commit_data["Variabilidades"][var]["Autores"] = [ author_name ]
            commit_data["Variabilidades"][var]["Arquivos"] = [ fname ]
    
    return commit_data