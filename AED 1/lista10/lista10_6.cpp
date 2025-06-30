#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

/*
    Escreva uma classe em C++ que gerencie jogos de loteria lotofacil. A classe deve permitir a
    escolha de 15 números que variam de 1 a 25. A escolha de um número deve ser feita em um
    método especializado. Caso o escolhido seja repetido, inferior a 1 ou superior a 25 seja escolhido,
    o sistema deve gerar uma exceção nesse método, que deve ser propagada e tratada no
    procedimento principal (main).
*/

class Lotofacil
{
private:
    int numeros[15];

public:
    void escolhaNumeros()
    {
        for (int i = 0; i < 15; i++)
        {
            numeros[i] = rand() % 26;
            for (int j = 0; j < i; j++)
            {
                if (numeros[i] == numeros[j - 1])
                {
                    throw 505;
                }
            }
        }
    }
};

int main()
{
    srand(time(NULL));
    Lotofacil x;
    try
    {
        x.escolhaNumeros();
    }
    catch (int num)
    {
        cout << "Tem um numero repetido, codigo de erro: " << num;
    }
}