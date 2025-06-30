#include <iostream>
#include <stdlib.h>
#include <string.h>

const int max_animais = 100;

using namespace std;

/*
    Crie um programa para gerenciar uma loja de animais de estimação. A loja vende cachorros e
    gatos. Cada animal possui um nome, raça, idade e preço. Faça um CRUD utilizando métodos setter
    e getters.
*/

class LojaAnimais
{
private:
    int id;
    char nome[50];
    char raca[20];
    int idade;
    float preco;

    void mostrar()
    {
        cout << "ID: " << id << endl;
        cout << "Nome: " << nome << endl;
        cout << "Raca: " << raca << endl;
        cout << "Idade: " << idade << " anos" << endl;
        cout << "Preco: R$" << preco << endl;
    }

    LojaAnimais *lista[max_animais];
    int total = 0;

    int buscarPorId(int idBusca)
    {
        for (int i = 0; i < total; i++)
        {
            if (lista[i]->id = idBusca)
            {
                return i;
            }
        }
        return -1;
    }

public:
    int getId()
    {
        return id;
    }

    char *getNome()
    {
        return nome;
    }

    char *getRaca()
    {
        return raca;
    }

    int getIdade()
    {
        return idade;
    }

    float getPreco()
    {
        return preco;
    }

    void setId(int id)
    {
        if (id < 0)
        {
            cout << "Id nao pode ser negativo";
            return;
        }

        this->id = id;
    }

    void setNome(char nome[])
    {
        strcpy(this->nome, nome);
    }

    void setRaca(char raca[])
    {
        strcpy(this->raca, raca);
    }

    void setIdade(int idade)
    {
        this->idade = idade;
    }

    void setPreco(float preco)
    {
        this->preco = preco;
    }

    LojaAnimais()
    {
        strcpy(nome, "Nome");
        strcpy(raca, "Raca");
        idade = 0;
        id = 0;
        preco = 0;
    }

    LojaAnimais(int id, char nome[], char raca[], int idade, float preco)
    {
        setId(id);
        setNome(nome);
        setRaca(raca);
        setIdade(idade);
        setPreco(preco);
    }

    void cadastrarAnimal()
    {
        if (total >= max_animais)
        {
            cout << "Maximo de animais cadastrados, remova um e tente novamente." << endl;
            return;
        }

        LojaAnimais novo;
        int id;
        char nome[50];
        char raca[20];
        int idade;
        float preco;

        cout << "Digite o id que sera cadastrado: ";
        cin >> id;

        if (buscarPorId(id) != -1)
        {
            cout << "ID já existe" << endl;
        }

        cout << "Digite o nome do animal: ";
        cin.ignore();
        cin.getline(nome, 50);

        novo.setNome(nome);

        cout << "Digite a raca do animal: ";
        cin.ignore();
        cin.getline(raca, 20);

        novo.setRaca(raca);

        cout << "Digite a idade do animal: ";
        cin >> idade;
        cin.clear();

        novo.setIdade(idade);

        cout << "Digite o preco do animal: ";
        cin >> preco;
        cin.clear();

        novo.setPreco(preco);

        lista[total++] = new LojaAnimais(novo);
        cout << "Animal cadastrado com sucesso." << endl;
    }

    void listarAnimais()
    {
        if (total == 0)
        {
            cout << "Nenhum animal cadastrado" << endl;
            return;
        }

        for (int i = 0; i < total; i++)
        {
            lista[i]->mostrar();
        }
    }

    void atualizarAnimais()
    {
        int id;
        char nome[50];
        char raca[20];
        int idade;
        int preco;

        cout << "Digite o ID do animal que quer atualizar: ";
        cin >> id;

        int idx = buscarPorId(id);

        if (idx == -1)
        {
            cout << "ID nao cadastrado";
        }
        else
        {
            lista[idx]->setId(id);

            cout << "Digite o novo nome do animal: ";
            cin.ignore();
            cin.getline(nome, 50);

            lista[idx]->setNome(nome);

            cout << "Digite a nova raca do animal: ";
            cin.ignore();
            cin.getline(raca, 20);

            lista[idx]->setRaca(raca);

            cout << "Digite a nova idade do animal: ";
            cin >> idade;
            cin.clear();

            lista[idx]->setIdade(idade);

            cout << "Digite o novo preco do animal: ";
            cin >> preco;
            cin.clear();

            lista[idx]->setPreco(preco);
        }
    }

    void deletarAnimais()
    {
        int id;

        cout << "Digite o ID do animal que quer atualizar: ";
        cin >> id;

        int idx = buscarPorId(id);

        if (idx == -1)
        {
            cout << "ID nao cadastrado";
        }
        else
        {
            delete lista[idx];

            for (int i = idx; i < total - 1; i++)
            {
                lista[i] = lista[i + 1];
            }
            total--;

            cout << "Pedido removido com sucesso!\n";
        }
    }
};