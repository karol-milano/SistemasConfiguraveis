#!/usr/bin/env Rscript

source("00_Funcoes.R")

desenvolvedoresPorArquivo <- function() {
  path <- "../resultados/"
  file.names <- dir(path)
  for (i in 1:length(file.names)) {
    valores <- lerPlanilhaAutores(file.names[i])
    gerarDesenvolvedoresPorArquivo(file.names[i], valores)
  }
}

gerarDesenvolvedoresPorArquivo <- function(projeto, valores) {
  #projeto <- "Gawk"
  #valores <- lerPlanilhaAutores(projeto)
  
  arq_var <- valores %>%
    select(Arquivo, Desenvolvedor)
  
  arq_var <- arq_var[complete.cases(arq_var), ]
  arq_var <- arq_var[!duplicated(arq_var[, c("Arquivo", "Desenvolvedor")]), ]
  
  arq_var <- arq_var %>%
    group_by(Arquivo) %>%
    summarise(Desenvolvedor = n())

  tabela <- paste("../resultados/", projeto, "/17_DesenvolvedoresPorArquivo.csv", sep = "")
  
  write.table(arq_var, file=tabela, sep=",", row.names=F)
  
  imagem <- paste("../resultados/", projeto, "/17_DesenvolvedoresPorArquivo.png", sep = "")
  
  png(file = imagem)
  
  p <- arq_var %>%
    ggplot(aes(x = "", y = Desenvolvedor)) + 
    geom_violin(fill="slateblue", draw_quantiles = c(0.25, 0.5, 0.75)) +
    geom_boxplot(width=0.1, fill="grey") +
    stat_summary(fun.data = n_fun, geom = "text", color = "red", size = 10) +
    theme(plot.title = element_text(size=22)) +
    labs(x = "Arquivos", y = "Quantidade de Desenvolvedores",
         title = "Desenvolvedores por arquivos")
  
  print(p)
  
  dev.off()
}
