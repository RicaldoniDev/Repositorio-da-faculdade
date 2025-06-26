#include <stdlib.h>
#include <stdio.h>

/*
    Uma sequência espelho trata-se de uma sequência que possui um número de início e um número de fim, e todos os números entre estes,
    inclusive estes, são dispostos em uma sequência crescente, sem espaços e, em seguida,esta sequência é projetada de forma invertida,
    como um reflexo no espelho. Por exemplo, se a sequência for de 1 a 5, o resultado ficaria 1234554321; já se a sequência for de 7 a 12,
    o resultado ficaria 789101112211101987.
    Escreva um programa que lê dois números inteiros e imprime a sequência espelho correspondente.
*/

int num_inverso(int num)
{
    int reversedNumber = 0, remainder;

    while (num != 0)
    {
        remainder = num % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        if (num % 10 == 0 && reversedNumber == 0)
        {
            printf("%d", 0);
        }
        num /= 10;
    }
    return reversedNumber;
}

int main()
{
    int menor, maior, num_reverso;

    scanf("%d", &menor);
    scanf("%d", &maior);

    for (int i = menor; i <= maior; i++)
    {
        printf("%d", i);
    }
    for (int i = maior; i >= menor; i--)
    {
        num_reverso = num_inverso(i);
        printf("%d", num_reverso);
    }
}