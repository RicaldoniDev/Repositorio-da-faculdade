#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

char maiorLexicografica(char string[], char maior[])
{
    int cont = 0;
    if (tolower(string[0]) > tolower(maior[0]))
    {
        strcpy(maior, string);
    }
    else if (tolower(string[0]) == tolower(maior[0]))
    {
        if (strlen(string) <= strlen(maior))
        {
            while (tolower(string[cont]) == tolower(maior[cont]) && cont <= strlen(string) - 1)
            {
                if (tolower(string[cont]) > tolower(maior[cont]))
                {
                    strcpy(maior, string);
                }
                cont++;
            }
        }
        else
        {
            while (tolower(string[cont]) == tolower(maior[cont]) && cont <= strlen(maior) - 1)
            {
                if (tolower(string[cont]) > tolower(maior[cont]))
                {
                    strcpy(maior, string);
                }
                cont++;
            }
        }
    }
}

int main()
{
    int num_strings;
    char string[300];
    char maior[300] = " ";
    char maior_lexicografica[300] = " ";

    // Digite o numero de strings
    scanf("%d", &num_strings);
    limpa_buffer();

    for (int i = 0; i < num_strings; i++)
    {
        // Digite uma string
        scanf("%[^\n]", &string);
        limpa_buffer();

        // Determina a string mais longa
        if (strlen(string) > strlen(maior))
        {
            strcpy(maior, string);
        }

        maiorLexicografica(string, maior_lexicografica);
    }
    printf("%s\n", maior);
    printf("%s", maior_lexicografica);
}