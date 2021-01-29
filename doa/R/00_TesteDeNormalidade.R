#!/usr/bin/env Rscript

source("00_Funcoes.R")

install.packages("dgof")
library(dgof)

# 12 projetos utilizados no teste
file.names <- c("Bison",   "Collectd", "Gnuplot", "LibPng",
                "Libssh",  "Lighttpd", "M4",      "OpenSC",
                "Openvpn", "Totem",    "Uwsgi",   "Xterm")

x <- data.frame()
for(i in 1:length(file.names)) {
  projeto <- file.names[i]
  valores <- lerPlanilhaVariabilidades(projeto)
  arq_var <- valores %>%
    select(Desenvolvedor, Arquivo, Variabilidade, Ownership_geral, Ownership_geral_n,
           Ownership_arquivo, Ownership_arquivo_n, Ownership_rlm, Ownership_rlm_n)
  
  arq_var <- arq_var %>%
    group_by(Desenvolvedor) %>%
    summarise(qtd_variabilidade = length(unique(Variabilidade)),
              ownership_arquivo = sum(Ownership_arquivo_n == 1),
              ownership_geral = sum(Ownership_geral_n == 1),
              ownership_rlm = sum(Ownership_rlm_n == 1))

  x <- rbind(x, arq_var)
}


## Testes de normalidade

# Teste de Shapiro-Wilk
shapiro.test(x$qtd_variabilidade)
shapiro.test(x$ownership_arquivo)
shapiro.test(x$ownership_geral)
shapiro.test(x$ownership_rlm)



# Teste de Kolmogorov-Smirnov
ks.test(arq_var$qtd_variabilidade, "pnorm", mean(arq_var$qtd_variabilidade), sd(arq_var$qtd_variabilidade))
ks.test(arq_var$ownership_arquivo, "pnorm", mean(arq_var$ownership_arquivo), sd(arq_var$ownership_arquivo))
ks.test(arq_var$ownership_geral, "pnorm", mean(arq_var$ownership_geral), sd(arq_var$ownership_geral))
ks.test(arq_var$ownership_rlm, "pnorm", mean(arq_var$ownership_rlm), sd(arq_var$ownership_rlm))

################################################################################


## Rankeamento de Spearman
for(i in 1:length(file.names)) {
  projeto <- file.names[i]
  valores <- lerPlanilhaVariabilidades(projeto)
  arq_var <- valores %>%
    select(Desenvolvedor, Arquivo, Variabilidade, Ownership_geral, Ownership_geral_n,
           Ownership_arquivo, Ownership_arquivo_n, Ownership_rlm, Ownership_rlm_n)
  
  arq_var <- arq_var %>%
    group_by(Desenvolvedor) %>%
    summarise(qtd_variabilidade = length(unique(Variabilidade)),
              ownership_arquivo = sum(Ownership_arquivo_n == 1),
              ownership_geral = sum(Ownership_geral_n == 1),
              ownership_rlm = sum(Ownership_rlm_n == 1))
  
  print(cor.test(arq_var$ownership_geral, arq_var$ownership_rlm, method = "spearman"))
  
  print(cor.test(arq_var$ownership_geral, arq_var$ownership_arquivo, method = "spearman"))
}



projeto <- "Bison"
valores <- lerPlanilhaVariabilidades(projeto)
arq_var <- valores %>%
  select(Desenvolvedor, Arquivo, Variabilidade, Ownership_geral, Ownership_geral_n,
         Ownership_arquivo, Ownership_arquivo_n, Ownership_rlm, Ownership_rlm_n)

arq_var <- arq_var %>%
  group_by(Arquivo) %>%
  summarise(qtd_variabilidade = length(unique(Variabilidade)),
            ownership_arquivo = sum(Ownership_arquivo_n == 1),
            ownership_geral = sum(Ownership_geral_n == 1),
            ownership_rlm = sum(Ownership_rlm_n == 1))


arq_var %>%
  ggplot(aes(x = "", y = qtd_variabilidade)) + 
  geom_violin(fill="slateblue", draw_quantiles = c(0.25, 0.5, 0.75)) +
  geom_boxplot(width=0.1, fill="grey") +
  stat_summary(fun.data = n_fun, geom = "text", color = "red", size = 10) +
  theme(legend.position = "none") +
  labs(x = "Arquivos", y = "Quantidade de Variabilidades",
       title = "Quantidade de variabilidades por arquivo"
  )
