#include <stdio.h>
#include <string.h>

int main() {
    // Carta 1 - Rio de Janeiro 
    char cidadeA[20] = "Rio de Janeiro";
    unsigned long populacaoA = 6211223;
    float areaA = 1182.3f;              // km²
    double pibA = 339700000000.0;       // R$

    int pontos_turisticosA = 1000;

    // Carta 2 - Curitiba 
    char cidadeB[20] = "Curitiba";
    unsigned long populacaoB = 1963726;
    float areaB = 435.0f;               // km²
    double pibB = 117000000000.0;       // R$

    int pontos_turisticosB = 300;

    // Cálculos auxiliares
    float densidadeA = populacaoA / areaA;
    float densidadeB = populacaoB / areaB;

    // ------ Variáveis de controle ------
    int atributo1, atributo2;
    float valorA1 = 0.0f, valorB1 = 0.0f, valorA2 = 0.0f, valorB2 = 0.0f;
    char nome1[40], nome2[40];
    int menor_vence1 = 0, menor_vence2 = 0;
    int i; // 

    // ===== MENU 1 =====
    printf("\n===== Escolha o 1º atributo =====\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (menor vence)\n");
    printf("Escolha: ");
    scanf("%d", &atributo1);

    switch (atributo1) {
        case 1: valorA1 = (float)populacaoA; valorB1 = (float)populacaoB; strcpy(nome1, "População"); break;
        case 2: valorA1 = areaA;             valorB1 = areaB;             strcpy(nome1, "Área"); break;
        case 3: valorA1 = (float)pibA;       valorB1 = (float)pibB;       strcpy(nome1, "PIB"); break;
        case 4: valorA1 = (float)pontos_turisticosA; valorB1 = (float)pontos_turisticosB; strcpy(nome1, "Pontos Turísticos"); break;
        case 5: valorA1 = densidadeA;        valorB1 = densidadeB;        strcpy(nome1, "Densidade Demográfica"); menor_vence1 = 1; break;
        default: printf("Opção inválida!\n"); return 0;
    }

    // ===== MENU 2 (dinâmico) =====
    printf("\n===== Escolha o 2º atributo (diferente do primeiro) =====\n");
    for (i = 1; i <= 5; i++) { 
        if (i != atributo1) {
            if (i == 1) printf("1 - População\n");
            if (i == 2) printf("2 - Área\n");
            if (i == 3) printf("3 - PIB\n");
            if (i == 4) printf("4 - Pontos Turísticos\n");
            if (i == 5) printf("5 - Densidade Demográfica (menor vence)\n");
        }
    }
    printf("Escolha: ");
    scanf("%d", &atributo2);

    if (atributo2 == atributo1) {
        printf("Você escolheu o mesmo atributo duas vezes. Tente novamente.\n");
        return 0;
    }

    switch (atributo2) {
        case 1: valorA2 = (float)populacaoA; valorB2 = (float)populacaoB; strcpy(nome2, "População"); break;
        case 2: valorA2 = areaA;             valorB2 = areaB;             strcpy(nome2, "Área"); break;
        case 3: valorA2 = (float)pibA;       valorB2 = (float)pibB;       strcpy(nome2, "PIB"); break;
        case 4: valorA2 = (float)pontos_turisticosA; valorB2 = (float)pontos_turisticosB; strcpy(nome2, "Pontos Turísticos"); break;
        case 5: valorA2 = densidadeA;        valorB2 = densidadeB;        strcpy(nome2, "Densidade Demográfica"); menor_vence2 = 1; break;
        default: printf("Opção inválida!\n"); return 0;
    }

    // ===== Comparações individuais =====
    int vencedor1 = 0, vencedor2 = 0;

    if (valorA1 != valorB1) {
        vencedor1 = menor_vence1 ? (valorA1 < valorB1 ? 1 : 2)
                                  : (valorA1 > valorB1 ? 1 : 2);
    }

    if (valorA2 != valorB2) {
        vencedor2 = menor_vence2 ? (valorA2 < valorB2 ? 1 : 2)
                                  : (valorA2 > valorB2 ? 1 : 2);
    }

    // ===== Soma final =====
    float somaA = valorA1 + valorA2;
    float somaB = valorB1 + valorB2;

    // ===== Saída =====
    printf("\n===== RESULTADO =====\n");
    printf("Cidade A: %s\n", cidadeA);
    printf(" - %s: %.2f\n", nome1, valorA1);
    printf(" - %s: %.2f\n", nome2, valorA2);

    printf("\nCidade B: %s\n", cidadeB);
    printf(" - %s: %.2f\n", nome1, valorB1);
    printf(" - %s: %.2f\n", nome2, valorB2);

    printf("\nSoma dos atributos:\n");
    printf(" - %s: %.2f\n", cidadeA, somaA);
    printf(" - %s: %.2f\n", cidadeB, somaB);

    if (somaA > somaB) {
        printf("\nVencedor: %s\n", cidadeA);
    } else if (somaB > somaA) {
        printf("\nVencedor: %s\n", cidadeB);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
