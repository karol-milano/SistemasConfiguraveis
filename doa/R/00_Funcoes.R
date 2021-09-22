#!/usr/bin/env Rscript

library(ineq)
library(dplyr)
library(readr)
library(ggplot2)
library(reshape2)


#' Função que encontra a mediana
#' 
#' @param data.frame x
#' @return Novo data.frame contendo a mediana
n_fun <- function(x) {
  return (data.frame(y = median(x), label = floor(median(x))))
}


#' Função que lê a planilha "Autores" do arquivo
#' 
#' @param projeto O nome do projeto que possui o arquivo de dados
#' @return Os valores lidos da planilha "Autores" do arquivo
lerPlanilhaAutores <- function(projeto) {
  arquivo <- paste("../resultados/", projeto, "/", projeto, "_Authors.csv", sep = "")
  
  print(paste("Lendo o arquivo", arquivo))
  valores <- read.csv(arquivo)
  dimnames(valores)[[2]] <- c(
    "Desenvolvedor", 
    "Arquivo", 
    "Qtd_variabilidades", 
    "Existencia_TRUE", 
    "Variabilidades", 
    "Qtd_commits", 
    "Commits", 
    "DOA_A", 
    "DOA_N", 
    "Classificacao", 
    "EhAutor")
  
  return (valores)
}


#' Função que lê a planilha "Commits" do arquivo
#' 
#' @param projeto O nome do projeto que possui o arquivo de dados
#' @return Os valores lidos da planilha "Commits" do arquivo
lerPlanilhaCommits <- function(projeto) {
  arquivo <- paste("../resultados/", projeto, "/", projeto, "_Commits.csv", sep = "")
  
  print(paste("Lendo arquivo", arquivo))
  valores <- read.csv(arquivo)
  dimnames(valores)[[2]] <- c(
    "Commit",
    "Data",
    "Desenvolvedor",
    "Arquivo",
    "Qtd_variabilidades",
    "Existencia_TRUE",
    "Variabilidades",
    "Classificacao",
    "EhAutor",
    "Ownership",
    "Classificacao_ownership",
    "Ownership_final",
    "Classificacao_ownership_final"
  )
  
  return (valores)
}


#' Função que lê a planilha "Variabilidades" do arquivo
#' 
#' @param projeto O nome do projeto que possui o arquivo de dados
#' @return Os valores lidos da planilha "Variabilidades" do arquivo
lerPlanilhaVariabilidades <- function(projeto) {
  arquivo <- paste("../resultados/", projeto, "/", projeto, "_Variabilities.csv", sep = "")
  
  print(paste("Lendo o arquivo", arquivo))
  valores <- read.csv(arquivo)
  dimnames(valores)[[2]] <- c(
    "Desenvolvedor", 
    "Variabilidade", 
    "fa_geral",
    "Qtd_commits_geral", 
    "Qtd_commits_dl", 
    "Qtd_commits_ac", 
    "Qtd_arquivos", 
    "Arquivo", 
    "Qtd_commits_arquivo", 
    "fa_arquivo", 
    "Ownership_perc",
    "Ownership_n",
    "Ownership_geral",
    "Ownership_geral_n",
    "Ownership_arquivo",
    "Ownership_arquivo_n",
    "Ownership_rlm",
    "Ownership_rlm_n")
  
  return (valores)
}
