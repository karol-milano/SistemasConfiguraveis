#!/usr/bin/env Rscript

source("00_Funcoes.R")

lcDesenvolvedoresPorCommitPeloTempo <- function() {
  path <- "../resultados/"
  file.names <- dir(path)
  for (i in 1:length(file.names)) {
    valores <- lerPlanilhaCommits(file.names[i])
    gerarLCDesenvolvedoresPorCommitPeloTempo(file.names[i], valores)
  }
}


#' Função que gera o gráfico LCDesenvolvedoresPorCommitPeloTempo
#' 
#' @param projeto O nome do projeto em que será feito a análise
#' @param valores Os dados lidos do arquivo
gerarLCDesenvolvedoresPorCommitPeloTempo <- function(projeto, valores) {
  #projeto <- "Hexchat"
  #valores <- lerPlanilhaCommits(projeto)
  
  arq_var <- valores %>%
    select(Desenvolvedor, Data, Commit, Classificacao_ownership)
  
  arq_var <- arq_var[complete.cases(arq_var), ]
  
  arq_var <- arq_var %>%
    group_by(Commit, Data, Classificacao_ownership) %>%
    summarise(Desenvolvedor = n())
  
  arq_var <- arrange(arq_var, Data)
  
  arq_var[ , "Total"] = sum(arq_var[ , "Desenvolvedor"])
  
  tabela <- paste("../resultados/", projeto, "/13_LCDesenvolvedoresPorCommitPeloTempoOwnerShip.csv", sep = "")
  
  write.table(arq_var, file=tabela, sep=",", row.names=F)
  
  imagem <- paste("../resultados/", projeto, "/13_LCDesenvolvedoresPorCommitPeloTempoOwnerShip.png", sep = "")
  
  png(file = imagem)
  
  plot(Lc(arq_var$Desenvolvedor, n = arq_var$Total), col="darkred", lwd=2)
  
  dev.off()
}
