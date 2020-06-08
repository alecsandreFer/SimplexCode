# SimplexCode
SimplexCode from Operacional Search - PO
Instituto: UNIVEM - Centro Universitário Euríedes Soares da Rocha - Marília
Curso: Bacharelado em Ciência da Computação
Turma: 5A-S
Integrantes do grupo:
  Alecsandre Ap. RA: 577200
  João V. Daum RA: 581491
  João Vitor De Oliveira Andrade RA: 582141
  Wagner Mafra dos Santos RA: 583154
  
  O Simplex é um algoritmo de otimização linear, no sentido de maximizar ou minimizar medidas para um melhor objetivo.
  Exemplo maximizar o lucro para utilizar menos recursos, ou talvez nas medidas corretas
  
  v1
  Este algoritmo pode:
  - Maximizar
  - Oferecer Soluções das iterações do algoritmo
  - Mostrar o passo a passo das operações
  - Fornecer um resultado
  
   Para utilizá-lo, basta executar o arquivo em um ambiente de desenvolvimento da linguagem C, por exemplo, Dev-C++.
  - Fornecer o número de variáveis e Restrições.
  - Fornecer nomes das variáveis(o que cada uma representa)
  - Fornecer Função Objetivo: O comportamento que se pretende seguir
  - Fornecer restrições, indicando o numero de recursos limitados quando fornecer o dado 'menor ou igual a <='.
  O algoritmo solucionará todo o resto, oferecendo as informações.
  
  Exemplo de Uso:        
            Simplex:
Digite a quantidade de varivaveis no problema:
3
Digite a quantidade de restricoes no problema:
4

Digite o que X1 representa> Tampa

Digite o que X2 representa> Suporte

Digite o que X3 representa> Plaqueta

Lembre-se que:
X1 = Tampa
X2 = Suporte
X3 = Plaqueta
Digite a Funcao Objetivo(FO):
Digite o valor de nX1(Tampa) da FO> 5

Digite o valor de nX2(Suporte) da FO> 7

Digite o valor de nX3(Plaqueta) da FO> 8

Funcao Objetivo: Max Z = 5.000X1 + 7.000X2 + 8.000X3

1a Restricao:

Digite o Valor de X1 na 1 restricao> 0.3

Digite o Valor de X2 na 1 restricao> 0.2

Digite o Valor de X3 na 1 restricao> 0.1

Deve ser <= (menor ou igual) a> 10000


2a Restricao:

Digite o Valor de X1 na 2 restricao> 0.003

Digite o Valor de X2 na 2 restricao> 0.005

Digite o Valor de X3 na 2 restricao> 0.007

Deve ser <= (menor ou igual) a> 1600


3a Restricao:

Digite o Valor de X1 na 3 restricao> 0.007

Digite o Valor de X2 na 3 restricao> 0.008

Digite o Valor de X3 na 3 restricao> 0.01

Deve ser <= (menor ou igual) a> 800


4a Restricao:

Digite o Valor de X1 na 4 restricao> 0.033

Digite o Valor de X2 na 4 restricao> 0.005

Digite o Valor de X3 na 4 restricao> 0.002

Deve ser <= (menor ou igual) a> 600


Base    X1      X2      X3      F1      F2      F3      F4      B
F1      0.300   0.200   0.100   1.000   0.000   0.000   0.000   10000.000
F2      0.003   0.005   0.007   0.000   1.000   0.000   0.000   1600.000
F3      0.007   0.008   0.010   0.000   0.000   1.000   0.000   800.000
F4      0.033   0.005   0.002   0.000   0.000   0.000   1.000   600.000
FO      -5.000  -7.000  -8.000  0.000   0.000   0.000   0.000   0.000

Solucao Basica Inicial:   X1 = 0.00  X2 = 0.00  X3 = 0.00  F1 = 10000.000  F2 = 1600.000  F3 = 800.000  F4 = 600.000  Z = 0.000



Base    X1      X2      X3      F1      F2      F3      F4      B
F1      0.230   0.120   0.000   1.000   0.000   -0.100  0.000   2000.000
F2      -0.002  -0.001  0.000   0.000   1.000   -0.007  0.000   1040.000
F3      0.700   0.800   1.000   0.000   0.000   1.000   0.000   80000.000
F4      0.032   0.003   0.000   0.000   0.000   -0.002  1.000   440.000
FO      0.600   -0.600  0.000   0.000   0.000   8.000   0.000   640000.000

2 Solucao:   X1 = 0.600  X2 = 0.00  X3 = 0.00  F1 = 2000.000  F2 = 1040.000  F3 = 79992.000  F4 = 440.000  Z = 640000.000



Base    X1      X2      X3      F1      F2      F3      F4      B
F1      1.917   1.000   0.000   1.000   0.000   -0.833  0.000   16666.668
F2      -0.001  0.000   0.000   0.001   1.000   -0.008  0.000   1050.000
F3      -0.833  0.000   1.000   -0.800  0.000   1.667   0.000   66666.664
F4      0.025   0.000   0.000   -0.003  0.000   0.001   1.000   383.333
FO      1.750   0.000   0.000   0.600   0.000   7.500   0.000   650000.000

3 Solucao:   X1 = 1.750  X2 = 0.00  X3 = 0.00  F1 = 16666.068  F2 = 1050.000  F3 = 66659.164  F4 = 383.333  Z = 650000.000
