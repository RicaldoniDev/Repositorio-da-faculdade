#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

/*
    Escreva um programa para cadastrar clientes de uma loja. As informações
   necessárias são: nome, data de nascimento, endereço e telefone. Devem ser
   usada classes para a construção deste cadastro.
*/

struct Data
{
    int dia;
    int mes;
    int ano;
};

class Cliente
{
private:
    char nome[50];
    Data nasc;
    char endereco[100];
    char telefone[11];

public:
    Cliente()
    {
        strcpy(nome, "Nome");
        nasc.dia = 1;
        nasc.mes = 1;
        nasc.ano = 1960;
        strcpy(endereco, "Endereco");
        strcpy(telefone, "00123456789");
    }

    char *getNome()
    {
        return nome;
    }

    Data getDataNasc()
    {
        return nasc;
    }

    char *getEndereco()
    {
        return endereco;
    }
    char *getTelefone()
    {
        return telefone;
    }

    void setNome(char nome[])
    {
        strcpy(this->nome, nome);
    }

    void setDataNasc(Data nasc)
    {
        this->nasc = nasc;
    }

    void setEndereco(char endereco[])
    {
        strcpy(this->endereco, endereco);
    }
    void setTelefone(char telefone[])
    {
        strcpy(this->telefone, telefone);
    }

    Cliente(char nome[], Data nasc, char endereco[100], char telefone[11])
    {
        setNome(nome);
        setDataNasc(nasc);
        setEndereco(endereco);
        setTelefone(telefone);
    }

    void cadastrarClientes(Cliente clientes[], int &cont, int max)
    {
        if (cont >= max)
        {
            cout << "Numero maximo de clientes cadastrados";
            return;
        }
        char nm[50], end[100], tel[11];
        Data nascimento;

        cin.ignore();
        cout << "Digite o nome do cliente: ";
        cin.getline(nome, 50);

        cout << "Digite o dia de nascimento do cliente: ";
        cin >> nascimento.dia;
        cout << "Digite o mes de nascimento do cliente: ";
        cin >> nascimento.mes;
        cout << "Digite o ano de nascimento do cliente: ";
        cin >> nascimento.ano;

        cin.ignore();
        cout << "Digite o endereco do cliente: ";
        cin.getline(nome, 100);

        cout << "Digite o telefone do cliente: ";
        cin >> tel;

        clientes[cont].setNome(nm);
        clientes[cont].setDataNasc(nascimento);
        clientes[cont].setEndereco(end);
        clientes[cont].setTelefone(tel);

        cont++;
    }
};

int main()
{
    int max, cont, opcao;

    cout << "Digite o maximo de cadastros: ";
    cin >> max;
    cin.clear();

    Cliente clientes[max];
    Cliente obj;
    do
    {
        cout << "\nEscolha o que deseja: " << endl;
        cout << "1 - Cadastro de clientes" << endl;
        cout << "0 - Sair" << endl;

        cin >> opcao;

        switch (opcao)
        {
        case 0:
            cout << "Saindo...";
            break;

        case 1:
            obj.cadastrarClientes(clientes, cont, max);
            break;

        default:
            cout << "Opcao invalida tente novamente";
            break;
        }

    } while (opcao != 0);
}