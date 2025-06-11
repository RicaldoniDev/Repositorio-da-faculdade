#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void limpa_buffer()
{
    /*
    Esta função de limpar buffer é necessária quando se tem que lidar com um menu
    e o usuário necessita digitar alguma coisa no terminal além da escolha do menu
    */
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void exercicio_1()
{
    /*
        Escreva um programa que leia da entrada padrão 5 números reais, que devem ser armazenados
        em um arranjo. Em seguida, gere outro arranjo, cujos valores correspondem ao dobro dos
        respectivos elementos do primeiro arranjo.
    */

    float conjunto_a[5];
    float conjunto_b[5];

    // Antes que pergunte "por que não fez isso com um loop", eu sei tanto da resposta quanto você
    printf("Digite 5 numeros reais: ");
    scanf("%f", &conjunto_a[0]);
    scanf("%f", &conjunto_a[1]);
    scanf("%f", &conjunto_a[2]);
    scanf("%f", &conjunto_a[3]);
    scanf("%f", &conjunto_a[4]);

    for (int i = 0; i < 5; i++)
    {
        conjunto_b[i] = conjunto_a[i] * 2;
    }

    printf("O dobro do conjunto: \n");

    for (int i = 0; i < 5; i++)
    {
        printf("%.2f ", conjunto_a[i]);
    }

    printf("\neh: ");

    for (int i = 0; i < 5; i++)
    {
        printf("%.2f ", conjunto_b[i]);
    }
}

void calculaMedia(int tam, int vetor[])
{
    float media = 0;
    int count = 0;

    for (int i = 0; i < tam; i++)
    {
        media += vetor[i];
    }

    for (int i = 0; i < tam; i++)
    {
        if (vetor[i] > media / tam)
        {
            count++;
        }
    }

    printf("A mediadas notas foi: %.2f", (float)media / tam);

    printf("\n%d alunos ficaram com notas acima da media", count);
}

void preencheNotas(int tam, int vetor[])
{
    for (int i = 0; i < tam; i++)
    {
        printf("Digite a nota do %dº aluno: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

void exercicio_2()
{
    /*
        Implemente um procedimento preencheNotas que receba e preencha um vetor com as notas
        de uma turma de 10 alunos. Faça um procedimento calculaMedia que receba um vetor
        preenchido com as notas, calcule a média da turma e conte quantos alunos obtiveram nota acima
        da média. Esse procedimento deve exibir a média e o resultado da contagem. Faça um programa
        (main) que declare e preencha as devidas o vetor com valores digitados e acione os
        procedimentos.
        void preencheNotas(int tam, int vetor[]);
        void calculaMedia(int tam, int vetor[]);
    */
    int notas[10];
    preencheNotas(10, notas);
    calculaMedia(10, notas);
}

void preencheValores(int x[], int y[], int length)
{
    for (int i = 0; i < length; i++)
    {
        x[i] = rand() % 11 + 10;
        y[i] = rand() % 11 + 10;
    }
}

void intercala(int x[], int y[], int length, int z[])
{
    int contx = 0;
    int conty = 0;

    for (int i = 0; i < length; i++)
    {
        if (i % 2 == 0)
        {
            z[i] = x[contx];
            contx++;
        }
        else
        {
            z[i] = y[conty];
            conty++;
        }
    }

    for (int i = 0; i < length; i++)
    {
        printf("%d ", z[i]);
    }
}

void exercicio_3()
{
    /*
        Implemente um procedimento preencheValores que preencha 2 vetores X e Y, com 10
        elementos cada com valores aleatórios entre 10 e 20. Implemente um procedimento que receba
        os dois vetores previamente preenchidos e gere um novo vetor Z com os elementos desses 2
        vetores intercalados de tal forma que nas posições ímpares do novo vetor estejam os elementos
        do primeiro vetor e nas posições pares os elementos do segundo vetor recebido por parâmetro.
        Faça um procedimento que receba e exiba o conteúdo de um vetor. Implemente um programa
        que faça as devidas declarações e acione os módulos para exemplificar o seu uso.
        void preencheValores(int x[], int y[], int length);
        void intercala(int x[], int y[], int length, int z[]);
    */

    srand(time(NULL));

    int array_x[10], array_y[10], array_z[10], length = 10;

    preencheValores(array_x, array_y, length);
    intercala(array_x, array_y, length, array_z);
}

bool validaSenha(char senha[])
{
    bool ok, res, maiusculo = 0, minusculo = 0, numero = 0, char_especial = 0;

    if (strlen(senha) < 8)
    {
        printf("Senha tem menos de 8 caracteres, tente novamente");
        return;
    }

    for (int i = 0; i < strlen(senha); i++)
    {
        if (isupper(senha[i]))
            maiusculo = true;

        if (islower(senha[i]))
            minusculo = true;

        if (isdigit(senha[i]))
            numero = true;

        if (!isalnum(senha[i]))
            char_especial = true;
    }
    res = maiusculo * minusculo * numero * char_especial;

    if (res == 0)
    {
        ok = false;
        printf("Senha inválida, tente novamente");
        return ok;
    }

    ok = true;
    printf("Senha válida!");
    return ok;
}

void exercicio_4()
{
    /*
        Peça ao usuário que crie uma senha. Utilize um arranjo de caracteres para armazenar a senha. Valide se a senha
        atende aos critérios de segurança, como ter pelo menos 8 caracteres, conter pelo menos uma
        letra maiúscula, uma letra minúscula, um número e um caractere especial. Imprima se a senha é
        válida ou não.
    */
    char senha[40];
    bool valida;
    int cont = 0;
    do
    {
        printf("\nCrie uma senha: ");
        scanf("%s", &senha);

        valida = validaSenha(senha);
    } while (!valida && cont < 5);
}

int validarEmail(char email[])
{
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
        {
            return i;
        }
    }
    return -1;
}

void exercicio_5()
{
    char email[50];
    int valido;

    printf("Digite seu e-mail: ");
    scanf("%s", &email);

    valido = validarEmail(email);

    if (valido == -1)
    {
        printf("Email invalido\n");
        return;
    }

    printf("Email valido, e  o \'@\' esta na posicao: %d", valido + 1);
}

void palavrasRepetidas(char texto[])
{
    int cont_palavras = 0, cont_letras = 0, max_letras = 0, i, j;

    for (int i = 0; i < strlen(texto); i++)
    {
        cont_letras++;
        if (texto[i] == ' ')
        {
            cont_palavras++;
            if (cont_letras > max_letras)
            {
                max_letras = cont_letras;
            }
            cont_letras = 0;
        }
    }
    char **palavras = (char **)malloc((cont_palavras + 1) * sizeof(char));

    for (i = 0; i < cont_palavras + 1; i++)
    {
        for (j = 0; palavras[i][j] != '\0'; j++)
        {
            palavras[i][j] = texto[i * j];
        }
    }
}

void exercicio_6()
{

    /*
        Crie um procedimento que recebe um vetor de caracteres. Esse procedimento deverá contar o
        número de palavras que são repetidas no texto e imprima a contagem de cada palavra repetida
        juntamente com sua frequência. Implemente o mais que solicita ao usuário o texto e chame o
        procedimento passando o vetor de caracteres.
    */
    char texto[100];
    printf("Digite um texto(Exercicio nao finalizado): ");
    scanf("%[^\n]", &texto);

    palavrasRepetidas(texto);
}

char *capitalizeString(char *vetor, int tamanho)
{
    char *maiusculo = (char *)malloc(tamanho * sizeof(char));
    for (int i = 0; i < strlen(vetor); i++)
    {
        maiusculo[i] = toupper(vetor[i]);
        printf("minusculo - %c, maiusculo - %c\n", vetor[i], maiusculo[i]);
    }
    printf("maiusculo %s", maiusculo[1]);
    return maiusculo;
}

void exercicio_7()
{
    /*
        Implemente a função abaixo, que receba como parâmetro uma string e converte,
        individualmente, cada caractere para maiúsculo. A função deverá retornar a string convertida
        para maiúsculo. A string a ser retornada deverá ser criada utilizando o comando malloc.

        char* capitalizeString(char *vetor, int tamanho);

        Ilustre o funcionamento da função criando um main que solicita ao usuário o texto e chama a
        função. O main deverá imprimir o resultado da função
    */
    const int TAM = 50;
    char texto[TAM], maiusculo[TAM];

    printf("Digite um texto de ate 50 caracteres: ");
    scanf("%[^\n]", &texto);

    strcpy(maiusculo, capitalizeString(texto, TAM));
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
               "6 - Exercicio 6\n"
               "7 - Exercicio 7\n"
               "8 - Sair\n");

        scanf("%d", &opcao);
        limpa_buffer();

        // A partir desta lista eu comecei a tratar o void exercicio_n() como o main de cada exercicio para melhor legibilidade
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
            printf("Saindo ...");
            break;

        default:
            printf("Opcao invalida! Tente novmente.");
            break;
        }
    } while (opcao != 8);
}