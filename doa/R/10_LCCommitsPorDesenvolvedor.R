#!/usr/bin/env Rscript

source("00_Funcoes.R")

lcCommitsPorDesenvolvedor <- function() {
  path <- "../resultados/"
  file.names <- dir(path)
  for (i in 1:length(file.names)) {
    valores <- lerPlanilhaCommits(file.names[i])
    gerarLCCommitsPorDesenvolvedor(file.names[i], valores)
  }
}


#' Função que gera o gráfico LCCommitsPorDesenvolvedor
#' 
#' @param projeto O nome do projeto em que será feito a análise
#' @param valores Os dados lidos do arquivo
gerarLCCommitsPorDesenvolvedor <- function(projeto, valores) {
  #projeto <- "Bison"
  #valores <- lerPlanilhaCommits(projeto)
  
  arq_var <- valores %>%
    select(Data, Desenvolvedor, Commit) %>%
    arrange(Data)
  
  arq_var <- arq_var[complete.cases(arq_var), ]
  arq_var <- arq_var[!duplicated(arq_var[, c("Desenvolvedor", "Commit")]), ]
  
  arq_var <- arq_var %>%
    group_by(Desenvolvedor, Data) %>%
    summarise(Commits = n()) %>%
    arrange(Data)
  
  arq_var[ , "Total"] = sum(arq_var[ , "Commits"])
  
  tabela <- paste("../resultados/", projeto, "/10_LCCommitsPorDesenvolvedorOwnership.csv", sep = "")
  
  write.table(arq_var, file=tabela, sep=",", row.names=F)
  
  imagem <- paste("../resultados/", projeto, "/10_LCCommitsPorDesenvolvedorOwnership.png", sep = "")
  
  png(file = imagem)
  
  plot(Lc(arq_var$Commits, n = arq_var$Total), col = "darkred", lwd = 2)
  
  dev.off()
}
