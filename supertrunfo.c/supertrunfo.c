#include <stdio.h>
#include <string.h>

#define NUM_CARTAS 2

typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

// Função para exibir os dados de uma carta
void exibirCarta(Carta c) {
    printf("Estado: %c\n", c.estado);
    printf("Código da Carta: %s\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.nomeCidade);
    printf("População: %d habitantes\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
}

// Função para comparar dois atributos
void compararCartas(Carta c1, Carta c2, int atributo1, int atributo2) {
    int pontosC1 = 0, pontosC2 = 0;

    // Comparação do primeiro atributo
    pontosC1 += (atributo1 == 1) ? (c1.populacao > c2.populacao ? 1 : 0) :
                (atributo1 == 2) ? (c1.area > c2.area ? 1 : 0) :
                (atributo1 == 3) ? (c1.pib > c2.pib ? 1 : 0) :
                (atributo1 == 4) ? (c1.pontosTuristicos > c2.pontosTuristicos ? 1 : 0) : 0;

    pontosC2 += (atributo1 == 1) ? (c2.populacao > c1.populacao ? 1 : 0) :
                (atributo1 == 2) ? (c2.area > c1.area ? 1 : 0) :
                (atributo1 == 3) ? (c2.pib > c1.pib ? 1 : 0) :
                (atributo1 == 4) ? (c2.pontosTuristicos > c1.pontosTuristicos ? 1 : 0) : 0;

    // Comparação do segundo atributo
    pontosC1 += (atributo2 == 1) ? (c1.populacao > c2.populacao ? 1 : 0) :
                (atributo2 == 2) ? (c1.area > c2.area ? 1 : 0) :
                (atributo2 == 3) ? (c1.pib > c2.pib ? 1 : 0) :
                (atributo2 == 4) ? (c1.pontosTuristicos > c2.pontosTuristicos ? 1 : 0) : 0;

    pontosC2 += (atributo2 == 1) ? (c2.populacao > c1.populacao ? 1 : 0) :
                (atributo2 == 2) ? (c2.area > c1.area ? 1 : 0) :
                (atributo2 == 3) ? (c2.pib > c1.pib ? 1 : 0) :
                (atributo2 == 4) ? (c2.pontosTuristicos > c1.pontosTuristicos ? 1 : 0) : 0;

    // Resultado
    printf("\n🔍 Resultado da Comparação:\n");
    if (pontosC1 > pontosC2) {
        printf("🏆 Carta 1 é a vencedora!\n");
        exibirCarta(c1);
    } else if (pontosC2 > pontosC1) {
        printf("🏆 Carta 2 é a vencedora!\n");
        exibirCarta(c2);
    } else {
        printf("🤝 Empate! Ambas as cartas têm desempenho equivalente nos atributos escolhidos.\n");
    }
}

int main() {
    Carta cartas[NUM_CARTAS];

    printf("=== Cadastro de Cartas Super Trunfo ===\n");

    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("\n--- Carta %d ---\n", i + 1);
        printf("Estado (A-H): ");
        scanf(" %c", &cartas[i].estado);

        printf("Código da Carta (ex: A01): ");
        scanf("%s", cartas[i].codigo);

        printf("Nome da Cidade: ");
        scanf(" %[^\n]", cartas[i].nomeCidade);

        printf("População: ");
        scanf("%d", &cartas[i].populacao);

        printf("Área (km²): ");
        scanf("%f", &cartas[i].area);

        printf("PIB (em bilhões): ");
        scanf("%f", &cartas[i].pib);

        printf("Número de Pontos Turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        printf("\n✅ Carta %d cadastrada com sucesso!\n", i + 1);
        exibirCarta(cartas[i]);
    }

    // Menu dinâmico para comparação
    int atributo1, atributo2;
    printf("\n=== Menu de Comparação ===\n");
    printf("Escolha dois atributos para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");

    printf("Digite o número do primeiro atributo: ");
    scanf("%d", &atributo1);

    printf("Digite o número do segundo atributo: ");
    scanf("%d", &atributo2);

    compararCartas(cartas[0], cartas[1], atributo1, atributo2);

    return 0;
}
