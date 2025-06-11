#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

float mediaPonderada(float n1, float n2, float n3) // Exercicio 1
{
    return (n1 * 5 + n2 * 3 + n3 * 2) / 10.0;
}

float mediaAritmetica(float n1, float n2, float n3) // Exercicio 1
{
    return (n1 + n2 + n3) / 3.0;
}

void medias() // Exercicio 1
{
    float n1, n2, n3;
    char tipo;
    printf("Digite o valor das 3 notas: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    if (n1 < 0 || n2 < 0 || n3 < 0)
    {
        printf("Uma das notas inseridas e invalida.");
        return;
    }

    printf("Digite se e media ponderada ou aritmetica (P ou A): ");
    scanf(" %c", &tipo);
    fflush(stdin);

    tipo = toupper(tipo);

    switch (tipo)
    {
    case 'P':
        printf("A media ponderada e: %.1f ", mediaPonderada(n1, n2, n3));
        break;

    case 'A':
        printf("A media aritmetica e: %.1f ", mediaAritmetica(n1, n2, n3));
        break;

    default:
        printf("Erro! Caractere invalido!");
        break;
    }
}

void exercicio_1() // Procedimento
{
    /* Escreva um procedimento que receba 3 notas de um aluno por parâmetro e uma letra. Se a
    letra for "A", o procedimento calcula e escreve a média aritmética das notas do aluno, se for
    "P", calcula e escreve a sua média ponderada (pesos: 5, 3 e 2). Escreva também um programa
    main que leia 3 notas de n alunos e acione o procedimento para cada aluno
    */
    medias();
}

void mediaSalarial() // Exercicio 2
{
    float salario, soma_salario = 0;
    int pessoas, soma_pessoas = 0;

    do
    {
        printf("Digite o salario familiar: ");
        scanf("%f", &salario);

        if (salario <= 0)
            continue;

        printf("Digite o numero de membros da familia: ");
        scanf("%d", &pessoas);

        if (pessoas < 0)
        {
            printf("Numero de pessoas invalido, tente novamente");
            continue;
        }

        soma_pessoas += pessoas;
        soma_salario += salario;

    } while (salario != 0);
    printf("A media salarial das familias inseridas e: %.2f\n", soma_salario / soma_pessoas);
}

void exercicio_2() // Procedimentow
{
    /*
        A prefeitura de uma cidade fez uma pesquisa entre os seus habitantes, coletando dados
        sobre o salário familiar e quantidade de membros (pais + filhos). Escreva um procedimento que
        leia esses dados para um número não determinado de famílias (ler até que salário igual 0),
        calcule e exiba a média de salário da população. Faça um programa main que acione o
        procedimento
    */
    mediaSalarial();
}

void organizar(int n1, int n2, int n3) // Exercicio 3
{
    if (n1 > n2 && n2 > n3)
    {
        printf("A ordem crescente e: %d %d %d\n", n3, n2, n1);
    }
    else if (n1 > n3 && n3 > n2)
    {
        printf("A ordem crescente e: %d %d %d\n", n2, n3, n1);
    }
    else if (n2 > n1 && n1 > n3)
    {
        printf("A ordem crescente e: %d %d %d\n", n3, n1, n2);
    }
    else if (n2 > n3 && n3 > n1)
    {
        printf("A ordem crescente e: %d %d %d\n", n1, n3, n2);
    }
    else if (n3 > n2 && n2 > n1)
    {
        printf("A ordem crescente e: %d %d %d\n", n1, n2, n3);
    }
    else if (n3 > n1 && n1 > n2)
    {
        printf("A ordem crescente e: %d %d %d\n", n2, n1, n3);
    }
}

void exercicio_3() // Procedimento
{
    /*
        Escreva um procedimento que recebe 3 valores inteiros por parâmetro e os exiba em ordem
        crescente. Faça um programa main que leia do teclado n conjuntos de 3 valores e acione o
        procedimento para cada conjunto.
    */
    int n1, n2, n3;

    printf("Digite 3 numeros: ");
    scanf("%d %d %d", &n1, &n2, &n3);

    organizar(n1, n2, n3);
}

int fatorial(int num) // Exercicio 4
{
    int res = 1;
    for (int i = 0; i < num; i++)
    {
        res *= num - i;
    }
    return res;
}

float exercicio_4(int n) // Funcao
{
    /*
        'Escreva uma função que receba como parâmetro um valor n inteiro positivo, calcule e
        'retorne o valor de E, definido pela equação abaixo
        'E=1+ 1/1! + 1/2! + 1/3! + ...+ 1/n!
    */
    float res = 1;
    for (int i = 1; i <= n; i++)
    {
        res += 1.0 / fatorial(i);
    }

    return res;
}

float exercicio_5(int n)
{
    float res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += (float)(pow(i, 2) + 1) / (i + 3);
        printf("Res de %d: %f\n", i, res);
    }
    return res;
}

void exercicio_6(float x, float y, float z) // Procedimento
{
    bool lados = x < y + z && y < x + z && z < x + y;

    if (lados)
    {
        if (x == y == z)
            printf("Triangulo Equilatero\n");
        else if (x == y || y == z || z == x)
            printf("Triangulo Isoceles\n");
        else
            printf("Triangilo Escaleno\n");
    }
    else
        printf("Triangulo invalido\n");
}

void exercicio_7()
{
    int n1, n2;

    printf("Digite 2 numeros: ");
    scanf("%d %d", &n1, &n2);

    if (&n1 > &n2)
        printf("O endereco do primeiro numero e maior do que o segundo e eh: %p\n", &n1);

    else
        printf("O endereco do segundo numero e maior do que o primeiro e eh: %p\n", &n2);
}

int main()
{
    // O professor nos deu a ideia de criar uma menu usando um switch e a partir desta lista eu começei a fazer desta forma
    int opcao;
    do
    {
        printf("Digite o exercicio: \n"
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
        // Em alguns casos eu tratei como função e o "main" do exercicio faz parte do caso
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
            int n1;

            printf("Digite um numero n: ");
            scanf("%d", &n1);

            printf("%.2f\n", exercicio_4(n1));
            break;

        case 5:
            int n2;
            printf("Digite um numero n: ");
            scanf("%d", &n2);

            printf("%.2f\n", exercicio_5(n2));

            break;

        case 6:
            float x, y, z;
            do
            {
                printf("Digite os 3 lados do triangulo (Digite 0 0 0 para sair): ");
                scanf("%f %f %f", &x, &y, &z);

                if (x == 0 && y == 0 && z == 0)
                    printf("Saindo do exercicio 6...\n");

                else
                    exercicio_6(x, y, z);

            } while (x != 0 || y != 0 || z != 0);
            break;

        case 7:
            exercicio_7();
            break;

        case 8:
            break;

        case 9:
            break;

        case 10:
            break;

        case 11:
            printf("Saindo...");
            break;

        default:
            printf("Exercicio invalido");
            break;
        }
    } while (opcao != 11);
}