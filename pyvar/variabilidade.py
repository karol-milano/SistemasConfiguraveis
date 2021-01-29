#!/usr/bin/env python
# -*- coding: utf-8 -*-

def create_variability(id_commit, author_name, file_name, date, var_name):
    var_data = {}
    var_data["Autores"] = {}
    var_data["Commits"] = {}
    var_data["Arquivos"] = {}

    commit = id_commit + "  -  " + date
    aname = author_name + "  -  " + date

    var_data["Autores"][author_name] = {}
    var_data["Autores"][author_name]["Arquivos"] = [ file_name ]
    var_data["Autores"][author_name]["Commits"] = [ commit ]

    var_data["Commits"][id_commit] = {}
    var_data["Commits"][id_commit]["Arquivos"] = [ file_name ]
    var_data["Commits"][id_commit]["Autores"] = [ aname ]

    var_data["Arquivos"][file_name] = {}
    var_data["Arquivos"][file_name]["Autores"] = [ author_name ]
    var_data["Arquivos"][file_name]["Commits"] = [ commit ]

    return var_data


def update_variability(var_data, id_commit, author_name, file_name, date, var_name):
    """
    """
    
    commit = id_commit + "  -  " + date
    aname = author_name + "  -  " + date

    if author_name in var_data["Autores"]:
        if file_name not in var_data["Autores"][author_name]["Arquivos"]:
            var_data["Autores"][author_name]["Arquivos"].append(file_name)
            
        if commit not in var_data["Autores"][author_name]["Commits"]:
            var_data["Autores"][author_name]["Commits"].append(commit)
    else:
        var_data["Autores"][author_name] = {}
        var_data["Autores"][author_name]["Arquivos"] = [ file_name ]
        var_data["Autores"][author_name]["Commits"] = [ commit ]

    if id_commit in var_data["Commits"]:
        if file_name not in var_data["Commits"][id_commit]["Arquivos"]:
            var_data["Commits"][id_commit]["Arquivos"].append(file_name)

        if aname not in var_data["Commits"][id_commit]["Autores"]:
            var_data["Commits"][id_commit]["Autores"].append(aname)
    else:
        var_data["Commits"][id_commit] = {}
        var_data["Commits"][id_commit]["Arquivos"] = [ file_name ]
        var_data["Commits"][id_commit]["Autores"] = [ aname ]

    if file_name in var_data["Arquivos"]:
        if author_name not in var_data["Arquivos"][file_name]["Autores"]:
            var_data["Arquivos"][file_name]["Autores"].append(author_name)

        if commit not in var_data["Arquivos"][file_name]["Commits"]:
            var_data["Arquivos"][file_name]["Commits"].append(commit)
    else:
        var_data["Arquivos"][file_name] = {}
        var_data["Arquivos"][file_name]["Autores"] = [ author_name ]
        var_data["Arquivos"][file_name]["Commits"] = [ commit ]
    
    return var_data