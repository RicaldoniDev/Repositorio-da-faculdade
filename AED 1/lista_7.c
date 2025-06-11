#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAM_MAX_LINHA 1000

struct Flor
{
    float sepal_len;
    float sepal_width;
    float petal_len;
    float petal_width;
    char species[100];
};

void contaLinhas(char nomeArquivo[])
{
    int contLinha = 0;
    char linha[TAM_MAX_LINHA];
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "r");
    if (!arquivo)
    {
        printf("Erro na abertura do arquivo: ");
        return;
    }
    while (fgets(linha, TAM_MAX_LINHA, arquivo) != NULL)
    {
        char *token = strtok(linha, ",");
        while (token != NULL)
        {
            int len = strlen(token);
            if (token[len - 1] == '\n')
            {
                contLinha++;
            }
            token = strtok(NULL, ",");
        }
    }
    fclose(arquivo);
    printf("A quantidade de linhas e: %d", contLinha);
}

void exercicio_1()
{
    /*
        Escreva um programa que contabilize e mostre a quantidade de linhas existentes no arquivo.
        O usuário deve digitar o nome do arquivo. Deve existir um procedimento que recebe o nome do
        arquivo já digitado e processa os dados.
    */
    char nome[100];
    printf("Digite o nome do arquivo: ");
    scanf("%s", &nome);

    contaLinhas(nome);
}

void contabilizaEspecies(char nome[])
{
    int cont_setosa = 0, cont_virginica = 0, cont_versicolor = 0;
    char linha[TAM_MAX_LINHA];
    FILE *arquivo;
    arquivo = fopen(nome, "r");
    if (!arquivo)
    {
        printf("Erro na abertura do arquivo: ");
        return;
    }
    while (fgets(linha, TAM_MAX_LINHA, arquivo) != NULL)
    {
        char *token = strtok(linha, ",");
        while (token != NULL)
        {
            if (*token == "setosa")
            {
                cont_setosa++;
            }
            else if (*token == "versicolor")
            {
                cont_versicolor++;
            }
            else if (*token == "virginica")
            {
                cont_virginica++;
            }
            token = strtok(NULL, ",");
        }
    }
    fclose(arquivo);
    printf("\nA quantidade de amostras de cada especie e de:\n"
           "Setosa: %d\n"
           "Versicolor: %d\n"
           "Virginica: %d",
           cont_setosa, cont_versicolor, cont_virginica);
}

void exercicio_2()
{
    /*
        Escreva um programa que contabilize a quantidade de amostras por espécie no arquivo.
        O usuário deve digitar o nome do arquivo.
        Deve existir um procedimento que recebe o nome do arquivo já digitado e processa os dados
    */

    char nome[100];
    printf("Digite o nome do arquivo: ");
    scanf("%s", &nome);

    contabilizaEspecies(nome);
}

void separaEspecies(char nomeArquivo[])
{
    char linha[TAM_MAX_LINHA], *pos;
    FILE *arquivo;
    FILE *arquivo_setosa;
    FILE *arquivo_virginica;
    FILE *arquivo_versicolor;

    arquivo_setosa = fopen("setosa.csv", "w");
    arquivo_virginica = fopen("virginica.csv", "w");
    arquivo_versicolor = fopen("versicolor.csv", "w");
    arquivo = fopen(nomeArquivo, "r");

    if (!arquivo || !arquivo_setosa || !arquivo_virginica || !arquivo_versicolor)
    {
        printf("Erro na abertura de algum arquivo");
    }

    while (fgets(linha, TAM_MAX_LINHA, arquivo))
    {
        if ((pos = strstr(linha, "setosa")))
        {
            fputs(linha, arquivo_setosa);
        }
        else if ((pos = strstr(linha, "versicolor")))
        {
            fputs(linha, arquivo_versicolor);
        }
        else if ((pos = strstr(linha, "virginica")))
        {
            fputs(linha, arquivo_virginica);
        }
    }

    fclose(arquivo);
    fclose(arquivo_setosa);
    fclose(arquivo_versicolor);
    fclose(arquivo_virginica);
}

void exercicio_3()
{
    /*
        Escreva um procedimento que separe os dados do arquivo “iris.csv” em três outros arquivos:
        “setosa.csv”, “versicolor.csv” e “virginica.csv”, cada um contendo os dados de uma espécie. O
        main deverá ser criado para chamar do procedimento.
    */
    char nome[100];
    printf("Digite o nome do arquivo: ");
    scanf("%s", &nome);

    separaEspecies(nome);
}

void copiaParaBinario(char nomeArquivo[])
{

    char linha[TAM_MAX_LINHA];
    FILE *arquivo;
    FILE *arquivo_binario;

    arquivo = fopen(nomeArquivo, "r");
    arquivo_binario = fopen("iris.bin", "wb");

    if (!arquivo || arquivo_binario == NULL)
    {
        printf("Erro na abertura de algum arquivo");
    }

    while (fgets(linha, TAM_MAX_LINHA, arquivo))
    {
        int len = strlen(linha);
        if (fwrite(linha, len * sizeof(char), 1, arquivo_binario) != 1)
        {
            printf("Erro na escrita do arquivo");
        }
    }

    fclose(arquivo);
    fclose(arquivo_binario);
}

void exercicio_5()
{
    /*
        Crie um procedimento que faça uma cópia do arquivo “iris.csv” em um arquivo BINÁRIO
        denominado “iris.bin”. O main deverá ser criado para chamar do procedimento
    */

    char nome[100];
    printf("Digite o nome do arquivo: ");
    scanf("%s", &nome);

    copiaParaBinario(nome);
}

int main()
{
    int opcao;
    do
    {
        printf("\nDigite o numero da opcao que deseja:\n"
               "1 - Exercicio 1\n"
               "2 - Exercicio 2\n"
               "3 - Exercicio 3\n"
               "4 - Exercicio 4\n"
               "5 - Exercicio 5\n"
               "6 - Sair\n");

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

        case 5:
            exercicio_5();
            break;

        case 6:
            printf("Saindo...");
            break;

        default:
            printf("Numero invalido, tente novamente");
        }
    } while (opcao != 6);
}
