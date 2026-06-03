#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 20
#define NOME_MAX 40

typedef struct No {
    int destino;
    struct No *proximo;
} No;

typedef struct {
    char nome[NOME_MAX];
    No *lista;
} Vertice;

typedef struct {
    Vertice vertices[MAX_VERTICES];
    int numVertices;
} Grafo;

void inicializarGrafo(Grafo *g) {
    g->numVertices = 0;
}

int adicionarVertice(Grafo *g, const char *nome) {
    if (g->numVertices >= MAX_VERTICES) {
        printf("Limite de vertices atingido.\n");
        return -1;
    }
    int id = g->numVertices;
    strncpy(g->vertices[id].nome, nome, NOME_MAX - 1);
    g->vertices[id].lista = NULL;
    g->numVertices++;
    return id;
}

void adicionarAresta(Grafo *g, int origem, int destino) {
    No *novo1 = (No *)malloc(sizeof(No));
    novo1->destino = destino;
    novo1->proximo = g->vertices[origem].lista;
    g->vertices[origem].lista = novo1;

    No *novo2 = (No *)malloc(sizeof(No));
    novo2->destino = origem;
    novo2->proximo = g->vertices[destino].lista;
    g->vertices[destino].lista = novo2;
}

void exibirGrafo(Grafo *g) {
    printf("\n=========================================\n");
    printf("   MAPA DO CAMPUS - UNIVERSIDADE POSITIVO\n");
    printf("=========================================\n\n");

    for (int i = 0; i < g->numVertices; i++) {
        printf("[%2d] %-30s -> ", i, g->vertices[i].nome);
        No *atual = g->vertices[i].lista;
        if (atual == NULL) {
            printf("(sem conexoes)");
        }
        while (atual != NULL) {
            printf("%s", g->vertices[atual->destino].nome);
            if (atual->proximo != NULL)
                printf(" | ");
            atual = atual->proximo;
        }
        printf("\n");
    }
    printf("\n");
}

void liberarGrafo(Grafo *g) {
    for (int i = 0; i < g->numVertices; i++) {
        No *atual = g->vertices[i].lista;
        while (atual != NULL) {
            No *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
        g->vertices[i].lista = NULL;
    }
}

void consultarConexoes(Grafo *g, int id) {
    if (id < 0 || id >= g->numVertices) {
        printf("Vertice invalido.\n");
        return;
    }
    printf("\nConexoes de [%s]:\n", g->vertices[id].nome);
    No *atual = g->vertices[id].lista;
    if (atual == NULL) {
        printf("  Nenhuma conexao encontrada.\n");
        return;
    }
    while (atual != NULL) {
        printf("  -> %s\n", g->vertices[atual->destino].nome);
        atual = atual->proximo;
    }
}

int main() {
    Grafo g;
    inicializarGrafo(&g);

    int entrada      = adicionarVertice(&g, "Entrada");
    int teatro       = adicionarVertice(&g, "Teatro Positivo");
    int ptOnibusO    = adicionarVertice(&g, "Ponto de Onibus Oeste");
    int blMarrom     = adicionarVertice(&g, "Bloco Marrom");
    int posGrad      = adicionarVertice(&g, "Pos-Graduacao");
    int reitoria     = adicionarVertice(&g, "Reitoria");
    int biblioteca   = adicionarVertice(&g, "Biblioteca");
    int eixoVivencia = adicionarVertice(&g, "Eixo de Vivencia");
    int blAzul       = adicionarVertice(&g, "Bloco Azul");
    int blAmarelo    = adicionarVertice(&g, "Bloco Amarelo/Praca");
    int blVermelho   = adicionarVertice(&g, "Bloco Vermelho");
    int ptOnibusC    = adicionarVertice(&g, "Ponto de Onibus Central");
    int clinicaFisio = adicionarVertice(&g, "Clinica de Fisioterapia");
    int ctEsportivo  = adicionarVertice(&g, "Centro Esportivo");
    int blBege       = adicionarVertice(&g, "Bloco Bege");
    int colPositivo  = adicionarVertice(&g, "Colegio Positivo Intl");
    int bosqueEC     = adicionarVertice(&g, "Bosque Eng. Civil");
    int bosqueEM     = adicionarVertice(&g, "Bosque Eng. Mecanica");
    int ptOnibusL    = adicionarVertice(&g, "Ponto de Onibus Leste");
    int bioterio     = adicionarVertice(&g, "Bioterio");

    adicionarAresta(&g, entrada,      ptOnibusO);
    adicionarAresta(&g, entrada,      teatro);
    adicionarAresta(&g, teatro,       eixoVivencia);
    adicionarAresta(&g, teatro,       blVermelho);
    adicionarAresta(&g, ptOnibusO,    blMarrom);
    adicionarAresta(&g, blMarrom,     reitoria);
    adicionarAresta(&g, blMarrom,     posGrad);
    adicionarAresta(&g, reitoria,     posGrad);
    adicionarAresta(&g, reitoria,     biblioteca);
    adicionarAresta(&g, reitoria,     eixoVivencia);
    adicionarAresta(&g, biblioteca,   posGrad);
    adicionarAresta(&g, biblioteca,   eixoVivencia);
    adicionarAresta(&g, eixoVivencia, blAzul);
    adicionarAresta(&g, eixoVivencia, blAmarelo);
    adicionarAresta(&g, blAzul,       blVermelho);
    adicionarAresta(&g, blVermelho,   ptOnibusC);
    adicionarAresta(&g, blVermelho,   blAmarelo);
    adicionarAresta(&g, blAmarelo,    clinicaFisio);
    adicionarAresta(&g, clinicaFisio, blBege);
    adicionarAresta(&g, clinicaFisio, ctEsportivo);
    adicionarAresta(&g, ctEsportivo,  blBege);
    adicionarAresta(&g, ctEsportivo,  colPositivo);
    adicionarAresta(&g, blBege,       colPositivo);
    adicionarAresta(&g, blBege,       bosqueEC);
    adicionarAresta(&g, bosqueEC,     bosqueEM);
    adicionarAresta(&g, bosqueEC,     ptOnibusL);
    adicionarAresta(&g, bosqueEM,     ptOnibusL);
    adicionarAresta(&g, colPositivo,  ptOnibusL);
    adicionarAresta(&g, ptOnibusC,    bioterio);

    exibirGrafo(&g);

    printf("-----------------------------------------\n");
    printf("Exemplo: onde posso ir a partir da Entrada?\n");
    consultarConexoes(&g, entrada);

    printf("\nExemplo: onde posso ir a partir do Eixo de Vivencia?\n");
    consultarConexoes(&g, eixoVivencia);

    liberarGrafo(&g);

    return 0;
}
