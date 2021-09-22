#!/usr/bin/env Rscript

source("00_Funcoes.R")

x <- data.frame()
path <- "../resultados/"
file.names <- dir(path)
for (i in 1:length(file.names)) {
  valores <- lerPlanilhaCommits(file.names[i])
  #valores <- lerPlanilhaCommits("GCC")
  
  arq_var <- valores %>%
    summarise(Arquivo_n = length(unique(Arquivo)),
              Desenvolvedor_n = length(unique(Desenvolvedor)),
              Commit_n = length(unique(Commit)),
              Variabilidades_n = length(unique(Variabilidades)),
              Data_extracao = max(Data)) %>%
    mutate(Projeto = file.names[i])
  
  arq_var <- arq_var %>%
    select(Projeto, everything())
  
  x <- rbind(x, arq_var)
}

write.table(x, file="Contagem.csv", sep=",", row.names=F)
