#!/usr/bin/env Rscript

source("00_Funcoes.R")

variabilidadesPorDesenvolvedor <- function() {
  path <- "../resultados/"
  file.names <- dir(path)
  for (i in 1:length(file.names)) {
    valores <- lerPlanilhaCommits(file.names[i])
    gerarVariabilidadesPorDesenvolvedor(file.names[i], valores)
  }
}


#' Função que gera o gráfico VariabilidadesPorDesenvolvedor
#' 
#' @param projeto O nome do projeto em que será feito a análise
#' @param valores Os dados lidos do arquivo
gerarVariabilidadesPorDesenvolvedor <- function(projeto, valores) {
  #projeto <- "Collected"
  #valores <- lerPlanilhaCommits(projeto)
  
  arq_var <- valores %>%
    select(Desenvolvedor, Variabilidades)

  arq_var <- arq_var[complete.cases(arq_var), ]
  arq_var <- arq_var[!duplicated(arq_var[, c("Desenvolvedor", "Variabilidades")]), ]
  arq_var <- arq_var[!apply(arq_var, 1, function(x) any(x=="")), ]
  
  arq_var <- arq_var %>%
    group_by(Desenvolvedor) %>%
    summarise(Variabilidades = n())
  
  tabela <- paste("../resultados/", projeto, "/03_VariabilidadesPorDesenvolvedor.csv", sep = "")
  
  write.table(arq_var, file=tabela, sep=",", row.names=F)
  
  imagem <- paste("../resultados/", projeto, "/03_VariabilidadesPorDesenvolvedor.png", sep = "")
  
  png(file = imagem)
  
  p <- arq_var %>%
    ggplot(aes(x = "", y = Variabilidades)) + 
    geom_violin(fill="slateblue", draw_quantiles = c(0.25, 0.5, 0.75)) +
    geom_boxplot(width=0.1, fill="grey") +
    stat_summary(fun.data = n_fun, geom = "text", color = "red", size = 10) +
    theme(legend.position = "none") +
    labs(x = "Desenvolvedor", y = "Quantidade de Variabilidades",
         title = "Quantidade de variabilidades por desenvolvedor"
    )
  
  print(p)
  
  dev.off()
  
}
