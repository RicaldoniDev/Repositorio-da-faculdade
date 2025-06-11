#include <stdlib.h>
#include <stdio.h>

void divisivel(int num)
{

    if (num % 3 == 0 && num % 5 == 0)
    {
        printf("Divisível por ambos\n");
    }
    else if (num % 3 == 0)
    {
        printf("Divisível por 3\n");
    }
    else if (num % 5 == 0)
    {
        printf("Divisível por 5\n");
    }
    else
    {
        printf("Não é divisível por 3 nem por 5\n");
    }
}

int main()
{
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int v[3];
    v[0] = n1;
    v[1] = n2;
    v[2] = n3;

    for (int i = 0; i < 3; i++)
    {
        divisivel(v[i]);
    }
}