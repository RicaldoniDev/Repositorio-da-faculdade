#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_LIN 10
#define MAX_COL 5

float soma_linha(int matriz[MAX_LIN][MAX_COL], int linha)
{
    int soma = 0;
    for (int i = 0; i < MAX_COL; i++)
    {
        printf("%d\n", matriz[linha - 1][i]);
        soma += matriz[linha - 1][i];
    }
    return soma;
}

void exercicio_1()
{
    /*
        Construa uma função que calcule e retorne a soma dos valores de uma linha i de uma matriz.
        A função deverá ter os seguintes argumentos:
        - A passagem por referência da matriz;
        - O número da linha a ser calculada.
    */
    int soma, linha, matriz[MAX_LIN][MAX_COL], i, j;

    for (i = 0; i < MAX_LIN; i++)
    {
        for (j = 0; j < MAX_COL; j++)
        {
            matriz[i][j] = 1;
        }
    }

    printf("Digite a linha que quer somar: ");
    scanf("%d", &linha);

    if (linha <= 0 || linha >= 5)
        printf("Erro! Numero da linha inválido");
    else
        soma = soma_linha(matriz, linha);
    printf("%d", soma);
}

int somaValores(int matriz[MAX_LIN][MAX_LIN])
{
    int soma = 0;
    for (int i = 0; i < MAX_LIN; i++)
    {
        for (int j = 0; j < MAX_LIN; j++)
        {
            if (i + j < MAX_LIN)
            {
                soma += matriz[i][i + j];
            }
        }
    }
    return soma;
}

void exercicio_2()
{
    /*
        Considere uma matriz quadrada MAX_LIN x MAX_LIN. Construa uma função que calcule
        a soma dos valores posicionados acima da diagonal principal.
    */

    int matriz[MAX_LIN][MAX_LIN], i, j;

    for (i = 0; i < MAX_LIN; i++)
    {
        for (j = 0; j < MAX_LIN; j++)
        {
            matriz[i][j] = rand() % 101;
        }
    }
    int soma = somaValores(matriz);
    printf("%d", soma);
}

void diagonalSecundaria(int matriz[MAX_LIN][MAX_LIN])
{
    int i, j;

    for (i = 0; i < MAX_LIN; i++)
    {
        for (j = 0; j < MAX_LIN; j++)
        {
            if (j == (MAX_LIN - 1) - i)
            {
                printf("%d\n", matriz[i][j]);
            }
        }
    }
}

void exercicio_3()
{
    /*
        Considere uma matriz quadrada MAX_LIN x MAX_LIN. Construa um procedimento que
        escreva os elementos da diagonal secundária.
    */
    int matriz[MAX_LIN][MAX_LIN], i, j;
    for (i = 0; i < MAX_LIN; i++)
    {
        for (j = 0; j < MAX_LIN; j++)
        {
            matriz[i][j] = j;
        }
    }
    diagonalSecundaria(matriz);
}

int compareInteiros(const void *a, const void *b) // Função necessaria para o qsort()
{
    return (*(int *)a - *(int *)b); /* possiveis opcoes de retorno sao 1, se a for maior que b, 0 se forem iguais e -1 se b for maior que a
                                       o cast de (int*) serve pro caso alguma variavel que nao e int for passada como argumento*/
}

void merge(int vet_a[], int vet_b[], int **vet_c_ptr, int tamanho)
{
    int cont_a = 0, cont_b = 0;
    *vet_c_ptr = (int *)malloc(tamanho * 2 * sizeof(int));
    for (int i = 0; i < tamanho * 2; i++)
    {
        if (i % 2 == 0)
        {
            (*vet_c_ptr)[i] = vet_a[cont_a];
            cont_a++;
        }
        else
        {
            (*vet_c_ptr)[i] = vet_b[cont_b];
            cont_b++;
        }
    }
    qsort((*vet_c_ptr), tamanho * 2, sizeof(int), compareInteiros);
}

void exercicio_4()
{
    /*
        Escreva um programa que preencha dois vetores de inteiros A e B com 4 números ordenados
        (em cada vetor). Em seguida, implemente um procedimento Merge, que receba os vetores A e B
        e retorne um vetor C ordenado, combinando os resultados dos vetores A e B. Imprima o vetor C
        na função main. A, B e C devem ser alocados usando malloc ou calloc.
        Obs. 1: O vetor C deve ser instanciado (“alocado”) no procedimento Merge.
        Obs. 2: Após a impressão dos valores, o comando free deve ser executado para liberação de
        memória dos vetores A, B e C.
        Ex.: A = {5, 8, 12, 16} , B = {3, 7, 14, 15} , C = {3, 5, 7, 8 ,12, 14, 15, 16}
    */
    int tamanho = 4;

    int *vet_a = (int *)malloc(tamanho * sizeof(int));
    int *vet_b = (int *)malloc(tamanho * sizeof(int));
    //    v Esta como ponteiro para poder ser retornado como referencia
    int *vet_c;

    for (int i = 0; i < tamanho; i++)
    {
        vet_a[i] = rand() % 21;
        vet_b[i] = rand() % 21;
    }

    // organiza os vetores em ordem cresente
    qsort(vet_a, tamanho, sizeof(int), compareInteiros);
    qsort(vet_b, tamanho, sizeof(int), compareInteiros);

    //                    vv necessario passar como ponteiro de ponteiro
    merge(vet_a, vet_b, &vet_c, tamanho);

    for (int i = 0; i < tamanho * 2; i++)
    {
        printf("vet - c %d\n", vet_c[i]);
    }
    free(vet_c);
}

void k_esimo(int vet_a[], int tamanho, int k)
{
    qsort(vet_a, tamanho, sizeof(int), compareInteiros);

    printf("k-esimo numero do vetor: %d", vet_a[k - 1]);
}

void exercicio_5()
{
    /*
        Desenvolva um programa que instancie um vetor de inteiros A utilizando malloc. O programa
        deve ler um valor k, onde k é positivo e menor que o tamanho do vetor (rejeite entradas
        inválidas). Implemente um procedimento que receba como parâmetros o vetor A, o tamanho do
        vetor |A| e o valor k. Retorne o k-ésimo menor elemento do vetor.
        Ex.: A = {3, 5, 7, 8 ,12, 14, 15, 16}, k = 3, retorno = 7.
    */

    int k, tamanho = MAX_LIN;
    int *vet = (int *)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++)
    {
        vet[i] = rand() % 51;
    }
    printf("Digite um numero: ");
    scanf("%d", &k);

    if (k - 1 < 0 || k - 1 > MAX_LIN)
    {
        printf("Entrada invalida!");
        return;
    }
    k_esimo(vet, tamanho, k);
}

void exercicio_6()
{
    /*
        Escreva um progama que leia do teclado um valor n. Instancie, usando o comando malloc, uma
        matriz de números em ponto flutuante Mn×n. Encontre (a) o maior elemento, (b) o menor
        elemento, (c) a média dos elementos da matriz.
    */

    int soma = 0, n, i, j;
    float media, menor, maior = 0;

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &n);

    float **m = (float **)malloc(n * sizeof(float));

    for (i = 0; i < n; i++)
    {

        m[i] = (float *)malloc(n * sizeof(float));

        for (j = 0; j < n; j++)
        {
            m[i][j] = rand() % 101;
        }
    }

    menor = m[0][0];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%.1f\n", m[i][j]);

            if (m[i][j] < menor)
            {
                menor = m[i][j];
            }

            if (m[i][j] > maior)
            {
                maior = m[i][j];
            }

            soma += m[i][j];
        }
    }
    media = (float)soma / (n * n);

    printf("\nO maior numero e: %.1f\n"
           "O menor numero e: %.1f\n"
           "A media e: %.1f",
           maior, menor, media);
}

struct Veiculo
{
    int id;
    float km;
};

void exercicio_7()
{
    int tamanho = 20, id_selecao, encontrado;
    struct Veiculo veiculos[tamanho];

    printf("Digite o id do veiculo selecionado: ");
    scanf("%d", &id_selecao);

    for (int i = 0; i < tamanho; i++)
    {
        veiculos[i].id = rand() % 1001 + 1000;
        veiculos[i].km = (float)rand() / (RAND_MAX / (rand() % 9000 + 1000));

        if (id_selecao == veiculos[i].id)
        {
            printf("Veiculo %d - id %d\n", i, veiculos[i].id);
            encontrado = 1;
        }
        else
        {
            encontrado = 0;
        }

        // printf("Veiculo %d: id - %d, km - %.2f\n", i + 1, veiculos[i].id, veiculos[i].km);
    }
    if (encontrado == 0)
    {
        printf("Veiculo nao encontrado");
    }
}

void exercicio_8()
{
    /*
        Escreva um programa que utilize alocação dinâmica para criar um vetor de 100 números de
        série de modelos de veículos cujos números são múltiplos de 4, mas que não terminam com o
        dígito 4. Certifique-se de que o vetor tenha exatamente 100 modelos e, ao final, libere a memória
        alocada
    */
    int tamanho = 10;
    int contador_id_divisivel_por_4 = 0;

    struct Veiculo *veiculos;

    veiculos = malloc(tamanho * sizeof(int));

    for (int i = 0; contador_id_divisivel_por_4 < tamanho; i++)
    {
        veiculos[contador_id_divisivel_por_4].id = rand() % 8999 + 1000;
        if (veiculos[i].id % 4 == 0)
        {
            if (veiculos[i].id != 4 && (veiculos[i].id - 4) % 10 != 0)
            {
                printf("%d\n", veiculos[contador_id_divisivel_por_4].id);
                contador_id_divisivel_por_4++;
            }
        }
    }
}

struct Veiculo maior_quilometragem(struct Veiculo veiculos[], int tamanho)
{
    struct Veiculo maior;
    maior.id = 0;
    maior.km = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (veiculos[i].km > maior.km)
        {
            maior = veiculos[i];
        }
    }
    return maior;
}

void troca_de_posicoes(struct Veiculo veiculos[], int tamanho, struct Veiculo maior)
{
    struct Veiculo temp;

    for (int i = 0; i < tamanho; i++)
    {
        if (veiculos[i].km == maior.km)
        {
            temp = veiculos[0];
            veiculos[0] = maior;
            veiculos[i] = temp;
        }
    }
}

void imprimir_quilometragens(struct Veiculo veiculos[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("id - %d | km - %.2f\n", veiculos[i].id, veiculos[i].km);
    }
}

void exercicio_9()
{
    /*
        Escreva um algoritmo que crie um vetor para armazenar 5 veículos(struct) e oferece ao usuário
        funcionalidades para:
        a) Procurar o veículo com a maior quilometragem.
        b) Troque o veículo com a maior quilometragem com o da primeira posição.
        c) Imprima a lista de quilometragens após a troca.
        Cada uma dessas etapas deve ser implementada em funções ou procedimentos separados.
    */
    int tamanho = 5;
    int selecao;

    struct Veiculo veiculos[5], maior;

    for (int i = 0; i < tamanho; i++)
    {
        veiculos[i].id = rand() % 1001 + 1000;
        veiculos[i].km = (float)rand() / (RAND_MAX / (rand() % 9000 + 1000));
    }

    maior = maior_quilometragem(veiculos, tamanho);

    do
    {
        printf("\nSelecione a opcao: \n"
               "1 - Maior quilometragem\n"
               "2 - Troca de posicoes\n"
               "3 - Imprimir quilometragem\n"
               "4 - Sair do exercicio 9\n");

        scanf("%d", &selecao);

        switch (selecao)
        {
        case 1:
            printf("O veiculo com maior quilometragem e o id - %d, com a quilometragem de %.2f km", maior.id, maior.km);
            break;

        case 2:
            troca_de_posicoes(veiculos, tamanho, maior);
            break;

        case 3:
            imprimir_quilometragens(veiculos, tamanho);
            break;

        case 4:
            printf("saindo do exercicio 9...");
            break;

        default:
            printf("Opcao invalida, tente novamente.");
            break;
        }
    } while (selecao != 4);
}

int main()
{
    srand(time(NULL));
    int opcao;
    do
    {
        printf("\nDigite o numero da opcao que deseja:\n"
               "1 - Exercicio 1\n"
               "2 - Exercicio 2\n"
               "3 - Exercicio 3\n"
               "4 - Exercicio 4\n"
               "5 - Exercicio 5\n"
               "6 - Exercicio 6\n"
               "7 - Exercicio 7\n"
               "8 - Exercicio 8\n"
               "9 - Exercicio 9\n"
               "10 - Exercicio 10\n"
               "11 - Sair\n");

        scanf("%d", &opcao);
        fflush(stdin);
        switch (opcao)
        {
        case 1:
            exercicio_1();
            break;

        case 2:
            exercicio_2();
            break;

        case 3:
            exercicio_3();
            break;

        case 4:
            exercicio_4();
            break;

        case 5:
            exercicio_5();
            break;

        case 6:
            exercicio_6();
            break;

        case 7:
            exercicio_7();
            break;

        case 8:
            exercicio_8();
            break;

        case 9:
            exercicio_9();
            break;

        case 10:
            // exercicio_10();
            break;

        case 11:
            printf("Saindo ...");
            break;

        default:
            printf("Opcao invalida! Tente novmente.");
            break;
        }
    } while (opcao != 11);
}
