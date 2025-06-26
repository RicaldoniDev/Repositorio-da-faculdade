#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

/*
    Desenvolva um sistema de comparação de preços de alimentos. Na primeira fase do seu
    software, gostaria de criar uma classe que contenha o nome da loja, telefone e preço de um
    alimento. Em seguida, irá cadastrar um total de 10 registros e exibir estatísticas desses itens, de
    modo que possa verificar o melhor preço (menor valor), o preço médio e o preço máximo. Crie
    classes e exiba as informações desejadas.
*/

class Loja
{
private:
    char nome[50];
    char telefone[12];
    float preco;

public:
    char *getNome()
    {
        return nome;
    }

    char *getTelefone()
    {
        return telefone;
    }

    float getPreco()
    {
        return preco;
    }

    void setNome(char nome[50])
    {
        strcpy(this->nome, nome);
    }

    void setTelefone(char telefone[12])
    {
        strcpy(this->telefone, telefone);
    }

    void setPreco(float preco)
    {
        this->preco = preco;
    }

    void cadastrarAlimento(Loja alimentos[], int &cont)
    {
        char nm[50], tel[12];
        float preco_alimento;
        cout << "Digite o nome da loja: ";

        cin.ignore();
        cin.getline(nm, 50);
        cin.clear();

        alimentos[cont].setNome(nm);

        cout << "Digite o telefone: ";
        cin >> tel;

        alimentos[cont].setTelefone(tel);

        cout << "Digite o preco do alimento: ";
        cin >> preco_alimento;

        alimentos[cont].setPreco(preco_alimento);

        cont++;
    };
};

int main()
{
    int num = 3 /*
                 * Autor: Juliano Ricaldoni Alves de Melo
                 * Arquivo Criado: 23/06/2025 10:11:59 am
                 */
        ,
        cont = 0, soma = 0;
    float media, maior = 0, menor = 999;
    Loja alimentos[num];
    Loja obj;

    for (int i = 0; i < num; i++)
    {
        obj.cadastrarAlimento(alimentos, cont);

        if (alimentos[i].getPreco() > maior)
        {
            maior = alimentos[i].getPreco();
        }

        if (alimentos[i].getPreco() < menor)
        {
            menor = alimentos[i].getPreco();
        }
        soma += alimentos[i].getPreco();
    }

    media = soma / num;
    cout << "O menor preco e: " << menor << endl;
    cout << "O maior preco e: " << maior << endl;
    cout << "A media do preco e: " << media;
}