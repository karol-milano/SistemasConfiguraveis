#!/usr/bin/env Rscript

source("00_Funcoes.R")

# Os arquivos a seguir utilizam a função lerPlanilhaAutores
source("01_VariabilidadesPorArquivo.R")
source("02_ArquivosPorDesenvolvedor.R")
source("03_TabelaComparacao.R")

# Os arquivos a seguir utilizam a função lerPlanilhaCommits
source("02_ArquivosPorCommit.R")
source("05_ClassificacaoPeloTempo.R")
source("05_ClassificacaoPeloTempoOwnerShip.R")
#source("06_PorcentagemClassificacaoPeloTempo.R")
#source("06_PorcentagemClassificacaoPeloTempoOwnerShip.R")
source("08_VariabilidadesPorDesenvolvedorPeloTempo.R")
source("09_LCCommitsPorDesenvolvedor.R")
source("09_LCVariabilidadesPorDesenvolvedor.R")
source("10_DesenvolvedoresPorVariabilidadePeloTempo.R")
source("11_LCDesenvolvedoresPorVariabilidade.R")
source("13_TabelaGini.R")

# ======================================================================= #

path <- "../resultados/"
file.names <- dir(path)
for (i in 1:length(file.names)) {
  projeto <- file.names[i]
  valores <- lerPlanilhaAutores(projeto)
  
  print(projeto)
  
  #   01_VariabilidadesPorArquivo
  print("|_ 01_gerarVariabilidadesPorArquivo")
  gerarVariabilidadesPorArquivo(projeto, valores)
  
  #   02_ArquivosPorDesenvolvedor
  print("|_ 02_gerarArquivosPorDesenvolvedor")
  gerarArquivosPorDesenvolvedor(projeto, valores)
  
  print("")  
# ======================================================================= #
  
  valores <- lerPlanilhaCommits(projeto)
  
  #   02_ArquivosPorCommit
  print("|_ 02_gerarArquivosPorCommit")
  gerarArquivosPorCommit(projeto, valores)
  
  #   05_ClassificacaoPeloTempo
  print("|_ 05_gerarClassificacaoPeloTempo")
  gerarClassificacaoPeloTempo(projeto, valores)
  
  #   06_PorcentagemClassificacaoPeloTempo
  #print("|_ 06_gerarPorcentagemClassificacaoPeloTempo")
  #gerarPorcentagemClassificacaoPeloTempo(projeto, valores)
  
  #   08_VariabilidadesPorDesenvolvedorPeloTempo
  print("|_ 08_gerarVariabilidadesPorDesenvolvedorPeloTempo")
  gerarVariabilidadesPorDesenvolvedorPeloTempo(projeto, valores)
  
  #   09_LCVariabilidadesPorDesenvolvedorPeloTempo
  print("|_ 09_gerarLCVariabilidadesPorDesenvolvedorPeloTempo")
  gerarLCVariabilidadesPorDesenvolvedor(projeto, valores)
  
  #   10_DesenvolvedoresPorVariabilidadePeloTempo
  print("|_ 10_gerarDesenvolvedoresPorVariabilidadePeloTempo")
  gerarDesenvolvedoresPorVariabilidadePeloTempo(projeto, valores)
  
  #   11_LCDesenvolvedoresPorVariabilidadePeloTempo
  print("|_ 11_gerarLCDesenvolvedoresPorVariabilidadePeloTempo")
  gerarLCDesenvolvedoresPorVariabilidade(projeto, valores)
  
  print("")
  print("# ======================================================================= #")
  print("")
}

# ======================================================================= #
#   03_TabelaComparacao
print("|_ 03_gerarTabelaComparacao")
tabelaComparacao()

# ======================================================================= #
#   13_TabelaGini
print("|_ 13_gerarTabelaGini")
tabelaGini()

