#include <stdio.h>  
#include <string.h> 
// --- Constantes ---

#define NUM_TERRITORIOS 5

#define MAX_NOME 100
#define MAX_COR 50

struct Territorio {
    char nome[MAX_NOME];
    char corExercito[MAX_COR];
    int numTropas;
};

int main() {
    
    // --- Declaração do Vetor ---
    struct Territorio mapa[NUM_TERRITORIOS];

    printf("=== CADASTRO DE TERRITÓRIOS (WAR) ===\n");
    printf("Por favor, insira os dados para os %d territórios.\n", NUM_TERRITORIOS);

    // --- 1. CADASTRO DOS DADOS (Entrada) ---
    // Usamos um loop 'for' para repetir o cadastro 5 vezes.
    for (int i = 0; i < NUM_TERRITORIOS; i++) {
        
        printf("\n--- Território %d ---\n", i + 1); // (i + 1) para mostrar de 1 a 5

        // Leitura do Nome (usando fgets)
        // 'fgets' é mais seguro para ler strings pois lê a linha inteira,
        // incluindo espaços (ex: "America do Sul").
        printf("Digite o nome: ");
        fgets(mapa[i].nome, MAX_NOME, stdin);
        
        // O fgets() captura o 'Enter' (\n) no final. 
        // Esta linha remove o '\n' para limpar a string.
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        // Leitura da Cor (usando fgets)
        printf("Digite a cor do exército: ");
        fgets(mapa[i].corExercito, MAX_COR, stdin);
        // Remove o '\n' da cor também
        mapa[i].corExercito[strcspn(mapa[i].corExercito, "\n")] = '\0';

        // Leitura do Número de Tropas (usando scanf)
        printf("Digite o número de tropas: ");
        scanf("%d", &mapa[i].numTropas);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // --- 2. EXIBIR O ESTADO ATUAL DO MAPA (Saída) ---
    // Impressão organizada dos dados de todos os territórios
    printf("\n\n======================================\n");
    printf("       ESTADO ATUAL DO MAPA       \n");
    printf("======================================\n");

    // Loop 'for' para percorrer o vetor 'mapa' e imprimir cada território
    for (int i = 0; i < NUM_TERRITORIOS; i++) {
        printf("\nTerritório: %s\n", mapa[i].nome);
        printf("  Exército: %s\n", mapa[i].corExercito);
        printf("  Tropas:   %d\n", mapa[i].numTropas);
        printf("--------------------------------------\n");
    }

    return 0; // Indica que o programa terminou com sucesso
}
