#!/usr/bin/env Rscript

library(dplyr)
library(ggplot2)

valores <- read.csv("Variabilities_final.csv")
dimnames(valores)[[2]] <- c(
  "Desenvolvedor", 
  "Variabilidade", 
  "fa_geral",
  "Qtd_commits_geral", 
  "Qtd_commits_dl", 
  "Qtd_commits_ac", 
  "Qtd_arquivos", 
  "Arquivo", 
  "Qtd_commits_arquivo", 
  "fa_arquivo", 
  "Ownership_perc",
  "Ownership_n",
  "Ownership_geral",
  "Ownership_geral_n",
  "Ownership_arquivo",
  "Ownership_arquivo_n",
  "Ownership_rlm",
  "Ownership_rlm_n")


var.test(valores$Ownership_rlm_n, valores$Ownership_arquivo_n)


arq_var <- valores %>%
  select(Variabilidade, Arquivo, Ownership_arquivo_n, Ownership_rlm_n) %>%
  group_by(Arquivo) %>%
  summarise(Variabilidade = n(),
            Ownership_arquivo = sum(Ownership_arquivo_n == 1.0),
            Ownership_rlm = sum(Ownership_rlm_n == 1.0))


cor.test(arq_var$Variabilidade, arq_var$Ownership_rlm, method = "pearson")

cor.test(arq_var$Variabilidade, arq_var$Ownership_rlm, method = "kendall")

cor.test(arq_var$Variabilidade, arq_var$Ownership_rlm, method = "spearman")


cor.test(arq_var$Variabilidade, arq_var$Ownership_arquivo, method = "pearson")

cor.test(arq_var$Variabilidade, arq_var$Ownership_arquivo, method = "kendall")

cor.test(arq_var$Variabilidade, arq_var$Ownership_arquivo, method = "spearman")


imagem <- "Ownership_arquivoPorVariabilidade.png"
png(file = imagem)

p <- ggplot(arq_var) +
  aes(x = Ownership_arquivo, y = Variabilidade) +
  geom_point(colour = "#0c4c8a") +
  labs(x = "Quantidade de proprietários", y = "Quantidade de variabilidades")
print(p)

dev.off()

imagem <- "Ownership_rlmPorVariabilidade.png"
png(file = imagem)

p <- ggplot(arq_var) +
  aes(x = Ownership_rlm, y = Variabilidade) +
  geom_point(colour = "#0c4c8a") +
  labs(x = "Ownership_rlm", y = "Quantidade de variabilidades")
print(p)

dev.off()