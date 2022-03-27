#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	int id;
	char nome[50];
	struct Node* next;
}node;

void add(node* base);
void remover(node* base);
void mostrar(node* base);

int main() {
	node* base = (node*)malloc(sizeof(node));
	base->next = NULL;
	base->id = 0;

	int escolha;

	do {
		printf("1 - Inserir\n");
		printf("2 - Exibir\n");
		printf("0 - Sair\n");
		printf("Entre com a opcao desejada: ");
		scanf_s("%d\n", &escolha);

		switch (escolha)
		{
		case 1:
			add(base);
			break;

		case 2:
			mostrar(base);
			break;

		}

	} while (escolha);

	return 0;
}

void add(node* base) {
	node* novo = (node*)malloc(sizeof(node));
	node* proximo = (node*)malloc(sizeof(node));
	node* aux = base;
	proximo = aux->next;
	do {
		if (aux->next == NULL) {
			printf("Qual o valor do novo: ");
			scanf_s("%d\n", &novo->val);
			aux->next = novo;
			base = aux;
			return 0;
		}
		aux->next = proximo;
		if(proximo->next != NULL)
		proximo = proximo->next;
	} while (aux->next != NULL);
}

void remover(node* base) {
	node* ante = base;
	node* aux = base;
	int valRemov;

	printf("Entre com o valor a ser removido: ");
	scanf_s("%d", &valRemov);

	while (aux->next != NULL) {
		ante = aux;
		aux = aux->next;
		if (aux->val == valRemov) {
			ante->next = aux->next;
			printf("O valor %d foi removido. \n", valRemov);
			return;
		}
	}
	printf("O valor %d nao existe na lista. \n", valRemov);
}

void mostrar(node* base) {
	node* aux = base;

	if (base->next == NULL) {
		printf("A lista esta vazia \n");
		return;
	}

	do {
		aux = aux->next;
		printf("-%d\n", aux->val);
	} while (aux->next != NULL);
}

