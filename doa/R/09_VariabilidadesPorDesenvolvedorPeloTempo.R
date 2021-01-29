#!/usr/bin/env Rscript

variabiliadadesPorDesenvolvedorPeloTempo <- function() {
  source("00_Funcoes.R")
  
  path <- "../resultados/"
  file.names <- dir(path)
  for (i in 1:length(file.names)) {
    valores <- lerPlanilhaCommits(file.names[i])
    gerarVariabilidadesPorDesenvolvedorPeloTempo(file.names[i], valores)
  }
}


#' Função que gera o gráfico VariabilidadesPorDesenvolvedorPeloTempo
#' 
#' @param projeto O nome do projeto em que será feito a análise
#' @param valores Os dados lidos do arquivo
gerarVariabilidadesPorDesenvolvedorPeloTempo <- function(projeto, valores) {
  #projeto <- "Cherokee"
  #valores <- lerPlanilhaCommits(projeto)
  
  arq_var <- valores %>%
    select(Desenvolvedor, Data, Variabilidades, EhAutor)
  
  arq_var <- arq_var[complete.cases(arq_var), ]
  arq_var <- arq_var[!duplicated(arq_var[, c("Desenvolvedor", "Data", "Variabilidades")]), ]
  
  arq_var <- arq_var %>%
    group_by(Desenvolvedor, Data, EhAutor) %>%
    summarise(Variabilidades = n())
  
  tabela <- paste("../resultados/", projeto, "/09_VariabilidadesPorDesenvolvedorPeloTempo.csv", sep = "")
  
  write.table(arq_var, file=tabela, sep=",", row.names=F)
  
  imagem <- paste("../resultados/", projeto, "/09_VariabilidadesPorDesenvolvedorPeloTempo.png", sep = "")
  
  png(file = imagem)
  
  p <- arq_var %>%
    ggplot(aes(x = EhAutor, y = Variabilidades, fill = EhAutor)) + 
    geom_violin(fill="slateblue", draw_quantiles = c(0.25, 0.5, 0.75)) + 
    geom_boxplot(width=0.1, fill="grey") +
    stat_summary(fun.data = n_fun, geom = "text", color = "red", size = 10) +
    theme(legend.position = "none") +
    labs(x = "Tipo de Desenvolvedor", y = "Quantidade de Variabilidades",
         title = "Variabilidades por tipo de desenvolvedor")
  
  print(p)
  
  dev.off()
}
