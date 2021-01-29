#!/usr/bin/env Rscript

source("00_Funcoes.R")

desenvolvedoresPorVariabilidadePeloTempo <- function() {
  path <- "../resultados/"
  file.names <- dir(path)
  for (i in 1:length(file.names)) {
    valores <- lerPlanilhaCommits(file.names[i])
    gerarDesenvolvedoresPorVariabilidadePeloTempo(file.names[i], valores)
  }
}


#' Função que gera o gráfico DesenvolvedoresPorVariabilidadePeloTempo
#' 
#' @param projeto O nome do projeto em que será feito a análise
#' @param valores Os dados lidos do arquivo
gerarDesenvolvedoresPorVariabilidadePeloTempo <- function(projeto, valores) {
  #projeto <- "Cherokee"
  #valores <- lerPlanilhaCommits(arquivo)
  
  arq_var <- valores %>%
    select(Desenvolvedor, Data, Variabilidades)
  
  arq_var <- arq_var[complete.cases(arq_var), ]
  arq_var <- arq_var[!duplicated(arq_var[, c("Desenvolvedor", "Data", "Variabilidades")]), ]
  
  arq_var <- arq_var %>%
    group_by(Variabilidades, Data) %>%
    summarise(Desenvolvedor = n())
  
  tabela <- paste("../resultados/", projeto, "/12_DesenvolvedoresPorVariabilidadePeloTempo.csv", sep = "")
  
  write.table(arq_var, file=tabela, sep=",", row.names=F)
  
  imagem <- paste("../resultados/", projeto, "/12_DesenvolvedoresPorVariabilidadePeloTempo.png", sep = "")
  
  png(file = imagem)
  
  p <- arq_var %>%
    ggplot(aes(x = "", y = Desenvolvedor)) + 
    geom_violin(fill="slateblue", draw_quantiles = c(0.25, 0.5, 0.75)) +
    geom_boxplot(width=0.1, fill="grey") +
    stat_summary(fun.data = n_fun, geom = "text", color = "red", size = 10) +
    theme(legend.position = "none") +
    labs(x = "Tipo de Desenvolvedor", y = "Quantidade de Variabilidades",
         title = "Tipo de desenvolvedor por variabilidades")
  
  print(p)
  
  dev.off()
}
