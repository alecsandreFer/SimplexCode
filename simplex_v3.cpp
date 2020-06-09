// Nomes: Alecsandre Ap. RA: 577200
//		  João V. Daum RA: 581491
// 		  João Vitor De Oliveira Andrade RA: 582141
//		  Wagner Mafra dos Santos RA: 583154

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct {
	char carac[60];	
} cadeia;

typedef struct {
	int x;
	int y;
} pivot;

typedef struct {
	char name;
	int num;
} var;



int main() {
	printf("\tSimplex:\t\n");
	printf("Deseja fazer uma Maximizacao ou um Minimizacao?");
	printf("\n1. Maximizar\n2. Minimizar\n");
	printf("Opcao> ");
	int op = 0;
	scanf("%i", &op);
	int quantVar = 0, quantRest = 0, x = 0, y = 0, po = 0, operar = 1, contSol = 1, SolImp = 0, varSolImp;
	printf("\n\nDigite a quantidade de varivaveis no problema> ");
	scanf("%i", &quantVar);
	printf("\nDigite a quantidade de restricoes no problema> ");
	scanf("%i", &quantRest);
	x = quantVar + quantRest + 1;
	y = quantRest + 1;
	cadeia represent[20];
	var cabecalho[quantVar + quantRest], coluna[quantRest];
	//float recursos[20];
	float matriz[x][y];
	
	for(int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			matriz[j][i] = 0;// zera matriz
		}
	}
	
	for (int i = 0; i < quantVar; i++) { // fornecendo nome de variaveis
		printf("\nDigite o que X%i representa> ", i + 1);
		fflush(stdin);
		gets(represent[i].carac);
	}
	
	fflush(stdin);
	
	printf("\nLembre-se que:"); // Lembrete
	for (int i = 0; i < quantVar; i++) {
		printf("\nX%i = %s", i + 1, represent[i].carac);
	}
	
	printf("\nDigite a Funcao Objetivo(FO):"); // Funcao Objetivo = Fornecer Linha FO
	for (int i = 0; i < quantVar; i++) {
		printf("\nDigite o valor de nX%i(%s) da FO> ", i + 1, represent[i]);
		scanf("%f", &matriz[i][y - 1]);  
		matriz[i][y - 1] = -matriz[i][y - 1];
	}
	
	if(op == 1) {
		printf("\nFuncao Objetivo: Max Z = "); // Printf FO
		for (int i = 0; i < quantVar; i++) {
			if (i < quantVar - 1) {
				printf("%.3fX%i + ", -matriz[i][y - 1], i + 1);
			} else {
				printf("%.3fX%i", -matriz[i][y - 1], i + 1);
			}
		}
	} else {
		printf("\nFuncao Objetivo: Min Z = "); // Printf FO
		for (int i = 0; i < quantVar; i++) {
			if (i < quantVar - 1) {
				printf("%.3fX%i + ", -matriz[i][y - 1], i + 1);
			} else {
				printf("%.3fX%i", -matriz[i][y - 1], i + 1);
			}
		}
	}
	
	for (int i = 0; i < quantRest; i++) { // fornecer Resticoes
		printf("\n\n%ia Restricao:\n", i + 1);
		for (int j = 0; j < quantVar + 1; j++) {
			if (j < quantVar) {
				printf("\nDigite o Valor de X%i na %i restricao> ", j + 1, i + 1);
				scanf("%f", &matriz[j][i]);
				if (matriz[j][i] < 0) { // condicao de parada na entrada de valores
					printf("\nValor Invalido\n");
					po = 1;
					break;
				}
			} else {
				printf("\nDeve ser <= (menor ou igual) a> ");
				varSolImp = i;
				scanf("%f", &matriz[x - 1][i]); // Fornecer Coluna B
			}
		}
		matriz[i + quantVar][i] = 1;  // Fornecer Valor da variavel de Folga
		if (po) //condicao de entrada de valores
			break;
	}
	for (int i = 0; i < quantRest; i++) {
		if (matriz[x-1][i] < 0) {
			printf("\n\nSolucao Impossivel. Valor de restricao %i em <= é negativo.\n", varSolImp);
			SolImp = 1;
			break;
		}
	}
	printf("\n");
	
	//crianco cabecalho
	for(int i = 0; i < x - 1; i++) {
		if (i < quantVar) {
			cabecalho[i].name = 'X';
			cabecalho[i].num = i + 1;
		} else {
			cabecalho[i].name = 'F';
			cabecalho[i].num = i + 1 - quantVar;
		}
	}	
	//criando colunas
	for(int i = 0; i < quantRest; i++) {
		coluna[i].name = 'F';
		coluna[i].num = i + 1;
	}
	
	do {
		pivot pivo;
		if (po) //condicao de entrada de valores
			break;
		if (SolImp) //tratamento de Solucao Impossivel
			break;
		
		for(int i = 0; i < x; i++) {
			if (matriz[i][y-1] < 0) { // condicao de parada
				operar = 1;
				break;
			} else {
				operar = 0;
			}
		}
		
		printf("\nBase \t");
		for (int a = 0; a < x - 1; a++) { // print Cabecalho Matriz
			printf("%c%i\t", cabecalho[a].name, cabecalho[a].num);
		}
		printf("B\t");
		
		for(int i = 0; i < y; i++) { // print Matriz
			printf("\n");
			if (i < y - 1) {
				printf("%c%i\t", coluna[i].name, coluna[i].num);
			} else {
				printf("FO\t");
			}
			for (int j = 0; j < x; j++) {
				printf("%.3f\t", matriz[j][i]);
			}
		}
		
		printf("\n");
		if (contSol <= 1) {
			printf("\nSolucao Basica Inicial: ");
			contSol++;
		} else {
			printf("\n%i Solucao: ", contSol);
			contSol++;
		}
		int nAchou[x - 1];
		for (int a = 0; a < x - 1; a++) { // print Solucao
			nAchou[a] = 1;
			printf("  %c%i = ", cabecalho[a].name, cabecalho[a].num);
			for(int i = 0; i < quantRest; i++) {
				if (cabecalho[a].name == coluna[i].name && cabecalho[a].num == coluna[i].num) {
					printf("%.3f", matriz[x - 1][i]);
					nAchou[a] = 0;
				}
			}
			if (nAchou[a])
				printf("0.000");
		}
		printf("  Z = ");
		printf("%.3f\n", matriz[x - 1][y - 1]);
		
		float menor = 0;
		var Aux;
		for(int i = 0; i < x - 1; i++) {
			if (matriz[i][y - 1] < menor) { // coletando menor coeficiente
				menor = matriz[i][y - 1];
				pivo.x = i;
				cabecalho[i];
			}
		}
		
		printf("\n");
		float matrizAux[x][y], matrizAux2[x][y];
		for (int j = 0; j < y; j++) {
			for (int i = 0; i < x; i++) {
				matrizAux[i][j] = matriz[i][j];
				matrizAux2[i][j] = matriz[i][j];
			}
		}
		
		float menor_pos = 10000000;
		for (int i = 0; i < quantRest; i++) {
			matrizAux[pivo.x][i] = matriz[x - 1][i] / matriz[pivo.x][i];
			if (matrizAux[pivo.x][i] < menor_pos && matrizAux[pivo.x][i] > 0) { // coletando maior coeficiente positivo
				menor_pos = matrizAux[pivo.x][i];
				pivo.y = i; // coleta linha pivo
			}
		}
		coluna[pivo.y] = cabecalho[pivo.x]; // troca
		float valor_pivo = matriz[pivo.x][pivo.y]; // matriz[2][2]
		for (int i = 0; i < x; i++) {
			if (i - quantVar != pivo.y) //5-3 = 2 
				matriz[i][pivo.y] = matriz[i][pivo.y] / valor_pivo; //calculando linha do pivot //transforma o pivo em 1, executando toda a linha junto
		}
		for (int i = 0; i < y; i++) {
			if (i != pivo.y)
				matriz[pivo.x][i] = 0; //(matriz[pivo.x][pivo.y] * matriz[pivo.x][i]) + matriz[pivo.x][i]; //zerando linhas de restricao do pivot, com excecao do pivot
		}
		printf("\n");
		for (int j = 0; j < y; j++) {
			float valor_linha_pivo;
			for (int i = 0; i < x; i++) {
				valor_linha_pivo = matriz[i][pivo.y];
				if (i != pivo.x && j != pivo.y)
					matriz[i][j] = (valor_linha_pivo * -matrizAux2[pivo.x][j]) + matrizAux2[i][j];
			}
		}
	} while (operar);
	return 0;
}
