#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMEROS 100

int main() {
    // Abertura do arquivo de entrada
    FILE *input = fopen("dados.txt", "r");
    if (!input) {
        printf("Erro ao abrir o arquivo dados.txt\n");
        return 1;
    }

// é lida a quantidade de números que serão analisados
    int n;
    fscanf(input, "%d", &n); 
    if (n > MAX_NUMEROS || n < 30) {
        printf("Erro: Quantidade de números fora do limite permitido\n");
        fclose(input);
        return 1;
    }

    // os numeros da file dados são adicionados ao array numeros
    int tamanho_numeros = 0;
    int numeros[n];
    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &numeros[i]);
        tamanho_numeros++;
    }
    
        int extra_num;
    if (fscanf(input, "%d", &extra_num) != EOF) {
        printf("Erro: O arquivo contém mais números do que o esperado\n");
        fclose(input);
        return 1;
    }
    fclose(input); // Fechando o arquivo após a leitura

    // Variáveis para armazenar as estatísticas
    int positivos = 0, negativos = 0, zeros = 0;
    int pares = 0, impares = 0;
    int diferentes[MAX_NUMEROS];
    int tamanho_diferentes = 0;
    

    // Loop para contagem de características e verificação de números únicos
    for (int i = 0; i < n; i++) {
        int num = numeros[i];
        
        // Contagem de positivos, negativos e zeros
        if (num > 0) positivos++;
        else if (num < 0) negativos++;
        else zeros++;

        // Contagem de pares e ímpares
        if (num % 2 == 0) pares++;
        else impares++;

        // Verificar se o número já foi contado como diferente
        int novo = 1;
        for (int j = 0; j < tamanho_diferentes; j++) {
            if (diferentes[j] == num) {
                novo = 0; // Já existe
                break;
            }
        }
        if (novo) {
            diferentes[tamanho_diferentes++] = num; // Adiciona se for novo
        }
    }

    // Abertura do arquivo de saída
    FILE *estatisticas = fopen("estatisticas.txt", "w");
    if (!estatisticas) {
        printf("Erro ao criar o arquivo estatisticas.txt\n");
        return 1;
    }

    // Escrita das estatísticas no arquivo
    fprintf(estatisticas, "Quantidade de numeros positivos: %d\n", positivos);
    fprintf(estatisticas, "Quantidade de numeros negativos: %d\n", negativos);
    fprintf(estatisticas, "Quantidade de numeros zero: %d\n", zeros);
    fprintf(estatisticas, "Quantidade de numeros pares: %d\n", pares);
    fprintf(estatisticas, "Quantidade de numeros impares: %d\n", impares);
    fprintf(estatisticas, "Quantidade de numeros diferentes: %d\n", tamanho_diferentes);
    
    fclose(estatisticas); // Fechando o arquivo de saída


    
    // é criada a file de distintos e conferido se realmente foi criada
    FILE *distintos = fopen("distintos.txt", "w");
    if (!distintos) {
        printf("Erro ao criar o arquivo distintos.txt\n");
        return 1;
    }

    // é inserida na file distintos os elementos presentes no array diferentes
    fprintf(distintos, "Numeros distintos entre si: ");
    for (int i = 0; i < tamanho_diferentes; i++) {
    fprintf(distintos, "%d ", diferentes[i]); // Imprime cada elemento do array
    }
    fprintf(distintos, "\n"); // Nova linha após imprimir todos os números
    fclose(distintos);


    // é criada a file de todos os numeros de entrada em forma não decrescente e conferido se realmente foi criada
    FILE *ordenado = fopen("ordenado.txt", "w");
    if (!ordenado) {
        printf("Erro ao criar o arquivo ordenado.txt\n");
        return 1;
    }

    // Elementos do array numeros são colocados em ordem não decrescentes e escritos na file
    for (int i = 0; i < tamanho_numeros; i++){
        for (int j = 0; j < tamanho_numeros - i - 1; j++){

            // Se o elemento atual for maior que o próximo, são trocados de lugar
            if (numeros[j] > numeros[j + 1]) {
                // Elementos são trocados
                int aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
            }
        }
    }

    fprintf(ordenado, "Numeros ordenados entre si: ");
    for (int i = 0; i < tamanho_numeros; i++) {
        fprintf(ordenado, "%d ", numeros[i]);
    }
    fprintf(ordenado, "\n"); // Nova linha é criada

    fclose(ordenado); // Fechando o arquivo


// é criada a file dos numeros distintos em forma não decrescente e conferido se realmente foi criada
    FILE *distintos_ordenado = fopen("distintos_ordenado.txt", "w");
    if (!distintos_ordenado) {
        printf("Erro ao criar o arquivo distintos_ordenado.txt\n");
        return 1;
    }

    // Elementos do array diferentes são colocados em ordem não decrescentes e escritos na file
    for (int i = 0; i < tamanho_diferentes; i++){
        for (int j = 0; j < tamanho_diferentes - i - 1; j++){

            // Se o elemento atual for maior que o próximo, são trocados de lugar
            if (diferentes[j] > diferentes[j + 1]) {
                // Elementos são trocados
                int aux = diferentes[j];
                diferentes[j] = diferentes[j + 1];
                diferentes[j + 1] = aux;
            }
        }
    }

    fprintf(distintos_ordenado, "Numeros distintos ordenados entre si: ");
    for (int i = 0; i < tamanho_diferentes; i++) {
        fprintf(distintos_ordenado, "%d ", diferentes[i]);
    }
    fprintf(distintos_ordenado, "\n"); // Nova linha é criada

    fclose(distintos_ordenado); // Fechando o arquivo

    return 0;
}
