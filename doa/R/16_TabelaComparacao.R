#!/usr/bin/env Rscript

tabelaComparacao <- function() {
  #source("00_Funcoes.R")

  x <- data.frame()
  path <- "../resultados/"
  file.names <- dir(path)
  for (i in 1:length(file.names)) {
    valores <- lerPlanilhaAutores(file.names[i])
    x <- rbind(x, gerarTabelaComparacao(file.names[i], valores))
  }
  
  write.table(x, file="16_TabelaComparacao.csv", sep=",", row.names=F)
}


#' Função que gera a tabela TabelaComparacao
#' 
#' @param projeto O nome do projeto em que será feito a análise
#' @param valores Os dados lidos do arquivo
gerarTabelaComparacao <- function(projeto, valores) {
  #projeto <- "Cherokee"
  #valores <- lerPlanilhaAutores(projeto)
  
  arq_var <- valores %>%
    select(Desenvolvedor, Classificacao, EhAutor)
  
  arq_var <- arq_var[complete.cases(arq_var), ]
  arq_var <- arq_var[!duplicated(arq_var[, c("Desenvolvedor", "Classificacao", "EhAutor")]), ]

  arq_var <- arq_var %>%
    summarise(Autor_Especialista = sum(Classificacao == "Especialista" & EhAutor == "EhAutor"),
              Autor_Generalista = sum(Classificacao == "Generalista" & EhAutor == "EhAutor"),
              Autor_Misto = sum(Classificacao == "Misto" & EhAutor == "EhAutor"),
              Colaborador_Especialista = sum(Classificacao == "Especialista" & EhAutor == "Colaborador"),
              Colaborador_Generalista = sum(Classificacao == "Generalista" & EhAutor == "Colaborador"),
              Colaborador_Misto = sum(Classificacao == "Misto" & EhAutor == "Colaborador")) %>%
    mutate(Projeto = projeto)
  
  arq_var <- arq_var %>%
    select(Projeto, everything())
  
  return (arq_var)
}
