#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 1001]

/* Balanço de Parênteses - Pilhas - URI 1068 */
/* Nathanael Martins R. da Silva */

typedef struct cel {
	char chave;
	struct cel *prox;
} celula;

void empilha_enc_C(char y, celula *t)
{
	celula *nova;
	nova = (celula *) malloc(sizeof (celula));
	nova->chave = y;
	nova->prox = t->prox;
	t->prox = nova;
}

int desempilha_enc_C(celula *t)
{
	int x;
	celula *p;
	if (t->prox != NULL) {
		p = t->prox;
		x = p->chave;
		t->prox = p->prox;
		free(p);
		return x;
	}
	else {
		return 0;
	}
}

int BalancParenteses(char *t)
{
	celula *lista;
	char c;

	lista = (celula *) malloc(sizeof(celula));
	lista->prox = NULL;
	
	while(*t != '\0')
	{
		if(*t == '(')
			empilha_enc_C(*t, lista);
		
		if(*t == ')') {
			c = desempilha_enc_C(lista);
			if(c == 0) 
				return 0;
			if(*t == '(' && c == ')') 
				return 0;
			}
		t++;
	}

	if(lista->prox == NULL)
		return 1;
	else
		return 0;
}

int main() {
	
	char cadeia[MAX];

	while(scanf("%s", cadeia) != EOF) {
		
		if(alancParenteses(cadeia) == 0)
			printf("incorrect\n");
		else
			printf("correct\n");
	}

	return 0;
}
