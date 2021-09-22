#!/usr/bin/env Rscript

source("00_Funcoes.R")



x <- data.frame()
#variabilidadesPorDesenvolvedor <- function() {
  path <- "../resultados/"
  #file.names <- dir(path)
  file.names <- c("GCC", "Mongo", "XServer")
  for (i in 1:length(file.names)) {
    valores <- lerPlanilhaCommits(file.names[i])
    
    arq_var <- valores %>%
    select(Desenvolvedor, Variabilidades)

    arq_var <- arq_var[complete.cases(arq_var), ]
    arq_var <- arq_var[!duplicated(arq_var[, c("Desenvolvedor", "Variabilidades")]), ]
    arq_var <- arq_var[!apply(arq_var, 1, function(x) any(x=="")), ]
    
    arq_var <- arq_var %>%
        group_by(Desenvolvedor) %>%
        summarise(Variabilidades = n()) %>%
        mutate(Projeto = file.names[i])
    
    arq_var <- arq_var %>%
    select(Projeto, everything())
  
    x <- rbind(x, arq_var)
  }
#}


imagem <- "../resultados/VariabilidadesPorDesenvolvedor.png"
  
  png(file = imagem)
  
  p <- x %>%
    ggplot(aes(x = Projeto, y = Variabilidades)) + 
    geom_violin(fill="slateblue", draw_quantiles = c(0.25, 0.5, 0.75)) +
    geom_boxplot(width=0.1, fill="grey") +
    stat_summary(fun.data = n_fun, geom = "text", color = "red", size = 10) +
    theme(legend.position = "none") +
    labs(x = "", y = "Number of Variabilities",
         title = "Variabilities by Developer"
    )
  
  print(p)
