#!/usr/bin/env Rscript

tabelaGini <- function() {
  #source("00_Funcoes.R")
  
  x <- data.frame()
  path <- "../resultados/"
  file.names <- dir(path)
  for (i in 1:length(file.names)) {
    valores <- lerPlanilhaCommits(file.names[i])
    x <- rbind(x, gerarTabelaGini(file.names[i], valores))
  }
  
  write.table(x, file="15_TabelaGini.csv", sep=",", row.names=F)
}


#' Função que gera a tabela TabelaGini
#' 
#' @param projeto O nome do projeto em que será feito a análise
#' @param valores Os dados lidos do arquivo
gerarTabelaGini <- function(projeto, valores) {
  #projeto <- "OpenSC"
  #valores <- lerPlanilhaCommits(projeto)
  
  ##############################################################################
  ##### Commits por Desenvolvedor
  ##############################################################################
  
  arq_var <- valores %>%
    select(Desenvolvedor, Commit)
  
  arq_var <- arq_var[complete.cases(arq_var), ]
  arq_var <- arq_var[!duplicated(arq_var[, c("Desenvolvedor", "Commit")]), ]
  
  arq_var <- arq_var %>%
    group_by(Desenvolvedor) %>%
    summarise(Commits = n())
  
  arq_var[ , "Cumulativo"] = cumsum(arq_var[ , "Commits"])
  
  commitsPorDesenvolvedor <- ineq(arq_var$Commits, n = arq_var$Cumulativo, type = "Gini")
  commitsPorDesenvolvedor
  
  ##############################################################################
  ##### Variabilidades por Desenvolvedor
  ##############################################################################
  
  arq_var <- valores %>%
    select(Desenvolvedor, Variabilidades)
  
  arq_var <- arq_var[complete.cases(arq_var), ]
  arq_var <- arq_var[!duplicated(arq_var[, c("Desenvolvedor", "Variabilidades")]), ]
  arq_var <- arq_var[!apply(arq_var, 1, function(x) any(x=="")), ]
  
  varpdes <- arq_var %>%
    group_by(Desenvolvedor) %>%
    summarise(Variabilidades = n())
  
  varpdes[ , "Cumulativo"] = cumsum(varpdes[ , "Variabilidades"])
  
  variabilidadesPorDesenvolvedor <- ineq(varpdes$Variabilidades, n = varpdes$Cumulativo, type = "Gini")
  variabilidadesPorDesenvolvedor
  
  ##############################################################################
  ##### Desenvolvedores por Variabilidade
  ##############################################################################
  
  despvar <- arq_var %>%
    group_by(Variabilidades) %>%
    summarise(Desenvolvedor = n())
  
  despvar[ , "Cumulativo"] = cumsum(despvar[ , "Desenvolvedor"])
  
  desenvolvedoresPorVariabilidade <- ineq(despvar$Desenvolvedor, n = despvar$Cumulativo, type = "Gini")
  desenvolvedoresPorVariabilidade
  
  ##############################################################################
  ##############################################################################
  
  retorno <- data.frame(
    Projeto = projeto,
    CommitsPorDesenvolvedor = commitsPorDesenvolvedor,
    VariabilidadesPorDesenvolvedor = variabilidadesPorDesenvolvedor,
    DesenvolvedoresPorVariabilidade = desenvolvedoresPorVariabilidade
  )
 
  return (retorno)
}
